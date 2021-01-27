/* Progame SW1 ON RELAY1
BY HS4QWC edit 27/1/2021 
YOUTUBE : 4Qchannal */ 

#include <16f84a.h>
#fuses NOWDT,NOPROTECT,XT
#use delay(clock=4000000)// 4 MHZ
#use fast_io(a)
#use fast_io(b)

#BYTE RA=5
#BYTE RB=6

#BIT SW1=RA.0
#BIT SW2=RA.1
#BIT SW3=RA.2
#BIT SW4=RA.3

#BIT UP=RB.0
#BIT DW=RB.1
#BIT SET_FFO_MOTOR=RA.4

#BIT CH1=RB.2
#BIT CH2=RB.3
#BIT CH3=RB.4
#BIT CH4=RB.5
#BIT MOTOR_UP=RB.6
#BIT MOTOR_DW=RB.7

short F_SW1,F_SW2,F_SW3,F_SW4,F_UP,F_DW,F_SET_FFO_MOTOR;
void main()
{
   
      set_tris_a(0xff);
      set_tris_b(0x03);
      
      CH1=0;
      CH2=0;
      CH3=0;
      CH4=0;
      
      MOTOR_UP=0;
      MOTOR_DW=0;
  
   while(true)
   {
      //****************************************/ 
        if(!SW1&&!F_SW1)//-----------------//ch1
        {
         CH1=~CH1;
         F_SW1=1;
         delay_ms(10);
        } 
        if(SW1&&F_SW1)  
          {
            F_SW1=0;
            delay_ms(10);
          }   
     /******************************************/     
        if(!SW2&&!F_SW2)//------------------//ch2
        {
         CH2=~CH2;
         F_SW2=1;delay_ms(10);
        } 
        if(SW2&&F_SW2)  
          {
            F_SW2=0;delay_ms(10);
          }   
        /*************************************/     
        if(!SW3&&!F_SW3)//------------------//ch3
        {
         CH3=~CH3;
         F_SW3=1;delay_ms(10);
        } 
         if(SW3&&F_SW3)
          {
            F_SW3=0;delay_ms(10);
          }   
       /********************************************/    
       if(!SW4&&!F_SW4)//---------------------//ch4
        {
         CH4=~CH4;
         F_SW4=1;delay_ms(10);
        } 
         if(SW4&&F_SW4)
          {
            F_SW4=0;delay_ms(10);
          }   
       /**********************************************/            
         if(!UP&&!F_UP)//---------------------//UP
        {
           MOTOR_UP=~MOTOR_UP;
           MOTOR_DW=0;
         F_UP=1;delay_ms(10);
        } 
         if(UP&&F_UP)
          {
            F_UP=0;delay_ms(10);
          }
          
            if(!DW&&!F_DW)//---------------------//DW
        {
           MOTOR_DW=~MOTOR_DW;
           MOTOR_UP=0;
         F_DW=1;delay_ms(10);
        } 
         if(DW&&F_DW)
          {
            F_DW=0;delay_ms(10);
          } 
          
       if(!SET_FFO_MOTOR&&!F_SET_FFO_MOTOR)//---------------------//DW
        {
           MOTOR_DW=0;
           MOTOR_UP=0;
         F_SET_FFO_MOTOR=1;delay_ms(10);
        } 
         if(SET_FFO_MOTOR&&F_SET_FFO_MOTOR)
          {
            F_SET_FFO_MOTOR=0;delay_ms(10);
          }          
   }

}
