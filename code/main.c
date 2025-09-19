#define VERSION_MAJOR 0
#define VERSION_MINOR 1

void count_to_ten(void){
    for(int i = 0; i<10; i++){
        printf("%d", i+1);
    }
}

int main(void){
    count_to_ten();
    while (1)
    {
        ;
    }
    
}