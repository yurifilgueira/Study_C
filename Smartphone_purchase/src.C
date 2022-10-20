#include <stdio.h>
#include <string.h>

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

typedef struct
{
    char model[40];
    int memory;
    double processor;
    double camera;
    double battery;
} Smartphone;

int registerSmartphone(int qttRegistered, Smartphone phones[])
{
    Smartphone newPhone;
    int memory, qtt = 0;
    double processor;
    double camera, battery;

    flush_in();
    fgets(newPhone.model, 40, stdin);
    scanf("%d %lf %lf %lf", &newPhone.memory, &newPhone.processor, &newPhone.camera, &newPhone.battery);
    phones[qttRegistered] = newPhone;
    return qttRegistered + 1;
}

int searchSmartphone(int qttRegistered, Smartphone phones[], Smartphone minimumReq)
{
    int qtt = 0;
    for (int i = 0; i < qttRegistered; i++)
    {
        if (phones[i].memory >= minimumReq.memory && phones[i].processor >= minimumReq.processor && phones[i].camera >= minimumReq.camera && phones[i].battery >= minimumReq.battery)
        {
            printf("Modelo: %s", phones[i].model);
            printf("Memoria: %dGB\n", phones[i].memory);
            printf("Processador: %.2fGhz\n", phones[i].processor);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n \n", phones[i].battery);
            qtt++;
        }
    }
    printf("%d smartphones encontrados. ", qtt);
}

int main()
{
    char yesOrNo;
    int memory, qttRegistered = 0;
    double processor, camera, battery;

    scanf("%c", &yesOrNo);

    Smartphone sp[50];
    Smartphone minimumReq;

    int i = 0;
    while (yesOrNo == 's')
    {
        qttRegistered = registerSmartphone(qttRegistered, sp);
        scanf(" %c", &yesOrNo);
    }

    scanf("%d %lf %lf %lf", &minimumReq.memory, &minimumReq.processor, &minimumReq.camera, &minimumReq.battery);
    qttRegistered = searchSmartphone(qttRegistered, sp, minimumReq);

    return 0;
}