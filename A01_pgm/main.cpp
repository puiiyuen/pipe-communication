#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#define REQUEST 100
#define PIVOT 200
#define LARGE 300
#define SMALL 400
#define READY 500
#define TERMINATE 600

#define READ_END 0
#define WRITE_END 1

using namespace std;

/*set up buffer, id*/

char buf[1024];
int id;



/*
 *******************
 * CHILD FUNCTIONS *
 *******************
 */


/*
 * function: child gets ID from parent by pipe[0]
 * param: fds: pipe
 * return: id of child
 */

int childGetId(int fds[][2]){
    close(fds[0][WRITE_END]);
    read(fds[0][READ_END],buf,sizeof(buf));
    id=atoi(buf);
    return id;
}

/*
 * function: child sends message to parent
 * param: fds: pipe, id: id of child, message: number or command
 */

void childSendParent(int fds[][2],int id,int message){
    close(fds[2*id-1][READ_END]);
    sprintf(buf,"%d",message);
    write(fds[2*id-1][WRITE_END],buf,sizeof(buf));
}

/*
 * function: child reads message from parent
 * param: fds: pipe, id: id of child
 * return: message from parent
 */

int childReadParent(int fds[][2],int id){
    int message;
    close(fds[2*id-2][WRITE_END]);
    read(fds[2*id-2][READ_END],buf, sizeof(buf));
    message=atoi(buf);
    return message;
}

/*
 * function: child reads file to get numbers
 * param: path: path of files, num: vector to store numbers
 * return: true: if read number from file and store in vector
 */

bool childReadFile(string path,vector<int> &num){
    string content;
    string temp;

    ifstream in(path);
    if(in.is_open()){
        getline(in,content);
        istringstream myNum(content);
        while(getline(myNum,temp,' ')){
            num.push_back(atoi(temp.c_str()));
        }
        in.close();
        return true;
    } else{
        return false;
    }
}

/*
 * function: child process
 * param: fds: pipe
 */

void child(int fds[][2]){

    id=childGetId(fds);

    vector<int> num;
//    string path="/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/input/input_";
//    string path="input_";
    string path="/mnt/hgfs/Study/Computer Science/CSCI3431/A01/A01_pgm/input_";
    path+=buf;
    path+=".txt";

    if(childReadFile(path,num))
    {
        sleep(5);
        childSendParent(fds,id,READY);
        printf("---Child %d sends READY\n",id);
    }

    int message,pivot=-2;

    while(true){

        //flag of array modification status
        bool modify=false;

        //get message from parent
        message=childReadParent(fds,id);

        //get pivot number
        if(message<100&&pivot==-1){
            pivot=message;
            int greatAmount=0;
            for (int i = 0; i < num.size(); ++i) {
                if (num[i]>pivot)
                    greatAmount++;
            }
            childSendParent(fds,id,greatAmount);
            printf("Child %d receives pivot and replies %d\n",id,greatAmount);
        }

        //get REQUEST message
        if(message==REQUEST){
                if(num.empty())
                    childSendParent(fds,id,-1);
                else{
                    int index=rand()%num.size();
                    childSendParent(fds,id,num[index]);
                }
        }

        //get PIVOT message
        if(message==PIVOT){
            pivot=-1;
            childSendParent(fds,id,READY);
        }

        //get SMALL message
        if (message==SMALL){
            for (int i = 0; i < num.size(); i++) {
                if(num[i]<pivot)
                    continue;
                else{
                    num.erase(num.begin(),num.begin()+i);
                    modify=true;
                    childSendParent(fds,id,READY);
                    break;
                }
            }
            if(!modify)
            {
                childSendParent(fds,id,READY);
            }
        }

        //get LARGE message
        if(message==LARGE){
            for (int i = 0; i < num.size(); i++) {
                if(num[i]<=pivot)
                    continue;
                else {
                    num.erase(num.begin() + i, num.end());
                    modify=true;
                    childSendParent(fds, id, READY);
                    break;
                }
            }
            if(!modify)
            {
                childSendParent(fds,id,READY);
            }
        }

        //get TERMINATE message
        if(message==TERMINATE){
            childSendParent(fds,id,READY);
            exit(0);
        }
    }
}

/*
 ***********************
 * CHILD FUNCTIONS END *
 ***********************
 */


/*
 ********************
 * PARENT FUNCTIONS *
 ********************
 */

/*
 * function: parent sends id to children by pipe[0]
 * parm: fds: pipe
 */

void parentSendId(int fds[][2]){
    for (int i = 0; i < 5; ++i) {
        close(fds[0][READ_END]);
        sprintf(buf,"%d",i+1);
        write(fds[0][WRITE_END],buf,sizeof(buf));
    }
}

/*
 * function: parent get READY signal from children
 *           when children finish reading files
 * param: fds: pipe
 */

bool parentGetReady(int fds[][2]){
    int sum=0,flag[5];
    while (1){
        for (int j = 0; j < 5; ++j) {
            close(fds[2*j+1][WRITE_END]);
            read(fds[2*j+1][READ_END],buf, sizeof(buf));
            if(atoi(buf)==READY)
                flag[j]=1;
        }
        for (int i = 0; i < 5; ++i) {
            sum+=flag[i];
        }
        if (sum==5){
            break;
        }
        sum=0;
    }
    return true;
}

/*
 * function: parent send message to child
 * param: fds: pipe, id: id of child, message: pivot number or command
 */

void parentSendChild(int fds[][2],int id,int message){
    close(fds[2*id-2][READ_END]);
    sprintf(buf,"%d",message);
    write(fds[2*id-2][WRITE_END],buf, sizeof(buf));
}

/*
 * function: parent get message from child
 * param: fds: pipe, id: id of child
 * return: message from child
 */

int parentReadChild(int fds[][2],int id){
    close(fds[2*id-1][WRITE_END]);
    read(fds[2*id-1][READ_END],buf, sizeof(buf));
    return atoi(buf);
}

/*
 * function: parent send messages to all children
 * param: fds: pipe, message: pivot number or command
 */

void parentBroadcasts(int fds[][2],int message){
    for (int i = 1; i <= 5; ++i) {
        parentSendChild(fds,i,message);
    }
}

/*
 * function: parent process
 * param: fds: pipe
 */

void parent(int fds[][2]){

    //parent send ids to children
    parentSendId(fds);

    //after children get ready, parent gets ready
    if(parentGetReady(fds))
        printf("---Parent READY\n");

    //initialize pivot number
    int pivot=-1;

    //n: amount of numbers
    int n=25;
    //k: amount of numbers that the numbers are larger than median number
    int k=n/2;

    while(1){
        while (pivot<0){
            id=rand()%5+1;
            parentSendChild(fds,id,REQUEST);
            printf("---Parent sends REQUEST to Child %d\n",id);
            pivot=parentReadChild(fds,id);
        }
        printf("pivot %d\n",pivot);
        parentBroadcasts(fds,PIVOT);
        for (int i = 1; i <= 5; ++i) {
            parentReadChild(fds,i);
        }
        parentBroadcasts(fds,pivot);

        int m=0,temp;
        printf("m=");
        for (int j = 1; j <= 5; ++j) {
            temp=parentReadChild(fds,j);
            m+=temp;
            printf("%d",temp);
            if(j==5)
                printf("=%d. \n",m);
            else
                printf("+");
        }

        //check if pivot is median
        if(m==k)
        {
            printf("%d=%d/2. ",m,k*2+1);
            printf("Median is found! Pivot: %d\n",pivot);
            printf("Parent sends kill signals to all children\n");
            parentBroadcasts(fds,TERMINATE);
            for (int i = 1; i <= 5; ++i) {
                if (parentReadChild(fds,i)==READY)
                    printf("Child %d terminates \n",i);
            }
            exit(0);
        }
        else if (m<k){
            parentBroadcasts(fds,LARGE);
            for (int i = 1; i <= 5; ++i) {
                parentReadChild(fds,i);
            }
            k=k-m;
            pivot=-1;
        }
        else{
            parentBroadcasts(fds,SMALL);
            for (int i = 1; i <= 5; ++i) {
                parentReadChild(fds,i);
            }
            pivot=-1;
        }
    }
}

/*
 ************************
 * PARENT FUNCTIONS END *
 ************************
 */


int main() {
    //rand seeds
    srand((unsigned)time(NULL));

    printf("Program running ...\n");

    //pipe
    int fds[10][2];
    for(int i=0;i<10;i++){
        pipe(fds[i]);
    }

    //create child processes
    for (int j = 0; j < 5; ++j) {
        if(fork()==0)
            child(fds);
    }

    //parent process
    parent(fds);

    return 0;
}