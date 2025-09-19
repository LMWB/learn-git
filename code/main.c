#define VERSION_MAJOR 0
#define VERSION_MINOR 1

void count_to_ten(void){
    for(int i = 0; i<10; i++){
        printf("%d", i+1);
    }
}

void print_version(void){
    printf("Version %d.%d",VERSION_MAJOR, VERSION_MINOR);
}

int main(void){

    print_version();

    count_to_ten();
    while (1)
    {
        ;
    }
}