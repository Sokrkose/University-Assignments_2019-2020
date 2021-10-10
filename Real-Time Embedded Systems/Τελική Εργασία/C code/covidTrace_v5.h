#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

#define N 1000
#define QUEUESIZE 200

FILE* timesFile;
FILE* uploadedContactsFile;

//48-bit (6*8-bit) MAC Address
typedef struct{ 
    uint8_t addressesTable[6];
}macaddress;

typedef struct{
    int isCloseContact;
    macaddress address;
    struct timeval update;
}contact; 

typedef struct{
    macaddress addressesTable;
    struct timeval timestamps[QUEUESIZE];
    long head, tail;
}possibleCloseContact; 


struct timeval timestamp, reference;

int NumberOfContacts = 0;

macaddress* MACs;
contact CloseContacts[N];
possibleCloseContact possibleContacts[N];

int lastContact = 0;



//returns positive test with 50% possibility
int testCOVID(void ){

    if((rand() % 101 + 1) > 50){    
        return 1;
    }
    return 0;

}

macaddress BTNearMe(void ){   

    return MACs[rand() % N];

}

void createListOfMACs(macaddress *macAddress,int numberOfPeople){
    
    int i = 0;
    for(i = 0; i < numberOfPeople; i++){
        int j = 0;
        for(j = 0; j < 6; j++){
            macAddress[i].addressesTable[j] = rand() % 10;
        }  
    }

    //Initialize the close contacts list
    int a = 0;
    for(a = 0; a < N; a++){
        CloseContacts[a].isCloseContact = 0;
        int b = 0;
        for(b = 0; b < 6; b++){
            CloseContacts[a].address.addressesTable[b] = MACs[a].addressesTable[b];
        }
    }

}

int equalMacs(macaddress a, macaddress b){

    int i = 0;
    for(i = 0; i < 6; i++){
        if(a.addressesTable[i] != b.addressesTable[i]) return 0;
    }
    return 1;

}

void timestampsInit(possibleCloseContact p){

  p.head = -1;
  p.tail = -1;

}

void pushTimestamps(possibleCloseContact p, struct timeval element){
  
    if (p.head == -1){
        p.head = 0;
    }
    p.tail = (p.tail + 1) % QUEUESIZE;
    p.timestamps[p.tail] = element;
    printf("seconds : %ld\tmicro seconds : %ld\n\n", element.tv_sec, element.tv_usec);
  
}

struct timeval popTimestamps(possibleCloseContact p){

    struct timeval element;
    
    element = p.timestamps[p.head];
    if(p.head == p.tail){
      p.head = -1;
      p.tail = -1;
    }else{
      p.head = (p.head + 1) % QUEUESIZE;
    }
    printf("seconds : %ld\nmicro seconds : %ld\n\n", element.tv_sec, element.tv_usec);
    return element;

}

void possibleContact(macaddress possibleMAC){  

    int existsFlag = 0;

    struct timeval time;
    gettimeofday(&time, NULL);

    int i = 0;
    for(i = 0; i < lastContact; i++){
        int isEqual = equalMacs(possibleMAC, possibleContacts[i].addressesTable);
        if(isEqual){
            pushTimestamps(possibleContacts[i], time);
            existsFlag = 1;
        }
    }

    if(!existsFlag){
        possibleContacts[lastContact].addressesTable = possibleMAC;
        timestampsInit(possibleContacts[lastContact]);
        pushTimestamps(possibleContacts[lastContact], time);
        lastContact++;
    }

}

void updateContacts(void ){

    int i = 0;
    for(i = 0 ; i < lastContact; i++){

        //if not empty
        if(possibleContacts[i].head != -1){

            struct timeval oldest = possibleContacts[i].timestamps[possibleContacts[i].head];
            struct timeval newest = possibleContacts[i].timestamps[possibleContacts[i].tail];
            struct timeval dt;
            timersub(&newest, &oldest, &dt);

            //if time > 2.4 & time < 12, it is a close contact
            if(dt.tv_sec > 2 && dt.tv_usec > 400000 && dt.tv_sec < 12){
                int j = 0;
                for(j = 0; j < N; j++){
                    //check in CloseContacts if already exists
                    if(equalMacs(possibleContacts[i].addressesTable, CloseContacts[j].address)){
                        CloseContacts[j].isCloseContact = 1;
                        CloseContacts[j].update = newest;
                    }
                }
            }

            if(dt.tv_sec > 12)  popTimestamps(possibleContacts[i]);

        }
    }

}

void uploadContacts(void ){
    
    uploadedContactsFile = fopen("./uploadedContacts.txt", "a+");
    
    int count = 0;
    struct timeval presestTime, positiveTime, lastContactTime;

    gettimeofday(&presestTime, NULL);
    timersub(&presestTime, &reference, &positiveTime);

    fprintf(uploadedContactsFile, "!!!!!!!!!!!!!!!!     Positive Test @ %ld:     !!!!!!!!!!!!!! \n", positiveTime.tv_sec);

    int i = 0;
    for(i = 0 ; i < N; i++){

        //check only which are the Close Contacts
        if(CloseContacts[i].isCloseContact == 1){

            timersub(&presestTime, &CloseContacts[i].update, &lastContactTime);

            //check if 14 days has passed
            if(lastContactTime.tv_sec > 12096){
                CloseContacts[i].isCloseContact = 0;
            }else{    
                fprintf(uploadedContactsFile, "%dth Contact has MAC Address:",count);
                int k = 0;
                for(k = 0; k < 6; k++){
                    fprintf(uploadedContactsFile, "%d", CloseContacts[i].address.addressesTable[k]);
                }
                fprintf(uploadedContactsFile, "\t Time span is: %ld\n", lastContactTime.tv_sec);
                count++;
            }
        }
    }

    fclose(uploadedContactsFile);

}