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

void new_feature(void){
    ;
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