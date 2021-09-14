#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PARTICIPANTS 5
#define MAX_PARTICIPANTNAME_LENGTH 32

int toGiftIndex(int _numParticpants, int _senderIndex, int _offset)
{
    return (_senderIndex + _offset) % _numParticpants;
}


int getOffset(int _numParticipants)
{
    srand(time(NULL));
    int randomOffset = rand();

    return (randomOffset % _numParticipants) ? 
        randomOffset : getOffset(_numParticipants);
}

int main(void)
{
    char participants[NUM_PARTICIPANTS][MAX_PARTICIPANTNAME_LENGTH] = {""};

    strcpy(participants[0], "Michael");
    strcpy(participants[1], "Alice");
    strcpy(participants[2], "Bob");
    strcpy(participants[3], "Charlie");
    strcpy(participants[4], "Dennis");

    int offset = getOffset(NUM_PARTICIPANTS);
    for (int i = 0; i < NUM_PARTICIPANTS; i++)
    {
        printf("%s:%s\n",
               participants[i],
               participants[toGiftIndex(NUM_PARTICIPANTS, i, offset)]);
    }

    exit(EXIT_SUCCESS);
}
