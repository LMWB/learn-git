#define VERSION_MAJOR 0
#define VERSION_MINOR 1

void count_to_ten(void){
    for(int i = 0; i<10; i++){
        printf("%d\n", i+1);
    }
}

void print_version(void){
    printf("Version %d.%d\n",VERSION_MAJOR, VERSION_MINOR);
}

void new_feature(void){
    for(int i = 0; i<5; i++){
        printf("new feature\n");
    }
}

int main(void){

    print_version();

    count_to_ten();

    new_feature();

    while (1)
    {
        ;
    }
}