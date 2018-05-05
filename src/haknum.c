#define  F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
int i =0;
   int num[10]={0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67,0x3F};
   int mynum[9]={0x00,0x00,num[7],num[9],num[3],num[4],num[1],num[6],num[0]};
   int control[3]={0x03,0x05,0x06};
   DDRE=0xFF;//포트 E번 출력 설정
   DDRB=0xFF;//포트 B번 출력 설정
    // Replace with your application code 
   PORTB=0x00;//E 포트 초기화
   PORTE=0x00;//B 포트 초기화
   while(1){
         for(i=0; i<7; i++){
            for(int j =0; j<100; j++){//100번 반복해서 출력한다.
            PORTB=control[0];
            PORTE=mynum[i+2];
            _delay_ms(1);//1 ms 킨다.
            PORTB=control[1];
            PORTE=mynum[i+1];
            _delay_ms(1);
            PORTB=control[2];
            PORTE=mynum[i];
            _delay_ms(1);
            PORTE=0x00;
            PORTB=0x00;
            }
            _delay_ms(100);//끄고 좀 대기
         }
      }
   }
