//###########################################################################
//
// FILE		: Motor.c
//
// TITLE	: Motor c file.
//
// Author	: Yuk Keun Ho
//
// Company	: Maze & Hz
//
//###########################################################################
// $Release Date: 2011.10.16 $
//###########################################################################

#define   _MOTOR_


#include "DSP280x_Device.h"
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
#include "Main.h"
#include "Motor.h"

interrupt void motor_ISR( void ){

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1 ;


	TxPrintf("%d___ %d___ %d\n ", counter.u16motor_str, counter.u16motor_flower,counter.u16motor_str2);
		/* str*/


		if( counter.u16motor_str >=  100) //  10  == 1000us
	{
		counter.u16motor_flower++;
				

		
		if( flag.u16str_section == 0  )
		{
		
			
			GpioDataRegs.GPASET.bit.GPIO23 = 1;	
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26= 1;
													//0.9
			flag.u16str_section = 1;
		}
		else if( flag.u16str_section == 1 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 2;
		}
		else if( flag.u16str_section == 2 )
		{

			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 3 ;
		}
		else if( flag.u16str_section == 3 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section =4 ;
		}
		else if( flag.u16str_section == 4 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 5 ;
		}
		else if( flag.u16str_section == 5 )
		{	

													
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 6 ;
		}
		else if( flag.u16str_section == 6 )
		{	

													
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13= 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 7 ;
		}
		else if( flag.u16str_section == 7 )
		{	
										
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 0 ;
		}
		else;
		
		counter.u16motor_str = 0 ;
	}
	else{
		counter.u16motor_str++ ;
		if(counter.u16motor_flower%50==0){
			counter.u16motor_str2++;
			}
			
		}

/* RPM */

	if( counter.u16motor_rpm >=  50)
	{
		if( flag.u16rpm_section == 0  )
		{
			GpioDataRegs.GPASET.bit.GPIO6 = 1;	
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10= 1;
													//0.9
			flag.u16rpm_section = 1;
		}
		else if( flag.u16rpm_section == 1 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section  = 2;
		}
		else if( flag.u16rpm_section == 2 )
		{

			GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 3 ;
		}
		else if( flag.u16rpm_section == 3 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section =4 ;
		}
		else if( flag.u16rpm_section == 4 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 5 ;
		}
		else if( flag.u16rpm_section == 5 )
		{	

													
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9= 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 6 ;
		}
		else if( flag.u16rpm_section == 6 )
		{	

													
			GpioDataRegs.GPASET.bit.GPIO6 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9= 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 7 ;
		}
		else if( flag.u16rpm_section == 7 )
		{	
										
			GpioDataRegs.GPASET.bit.GPIO6 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 0 ;
		}
		else;
		
		counter.u16motor_rpm = 0 ;
	}
	else{
		counter.u16motor_rpm++ ;
	}
	


	

		
		

}


void snail(){



		/* str*/


		if( counter.u16motor_str >=  200) //  10  == 1000us
	{
		counter.u16motor_stop++;								//   stop
 															//

		if(counter.u16motor_stop==1200)
		{
			
				GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
				GpioDataRegs.GPASET.bit.GPIO7 = 1;
				GpioDataRegs.GPASET.bit.GPIO9 = 1;
				GpioDataRegs.GPASET.bit.GPIO10 = 1;  

				DELAY_US(1000000);

				GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
				GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
				GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
				GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;  

				
			StopCpuTimer0();

		}
		
		if( flag.u16str_section == 0  )
		{
			GpioDataRegs.GPASET.bit.GPIO23 = 1;	
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26= 1;
													//0.9
			flag.u16str_section = 1;
		}
		else if( flag.u16str_section == 1 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 2;
		}
		else if( flag.u16str_section == 2 )
		{

			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 3 ;
		}
		else if( flag.u16str_section == 3 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section =4 ;
		}
		else if( flag.u16str_section == 4 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 5 ;
		}
		else if( flag.u16str_section == 5 )
		{	

													
			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 6 ;
		}
		else if( flag.u16str_section == 6 )
		{	

													
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13= 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 7 ;
		}
		else if( flag.u16str_section == 7 )
		{	
										
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
													//0.9
			flag.u16str_section = 0 ;
		}
		else;
		
		counter.u16motor_str = 0 ;
	}
	else{
		counter.u16motor_str++ ;
	}

/* RPM */

	if( counter.u16motor_rpm >=  50)
	{
		if( flag.u16rpm_section == 0  )
		{
			GpioDataRegs.GPASET.bit.GPIO6 = 1;	
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10= 1;
													//0.9
			flag.u16rpm_section = 1;
		}
		else if( flag.u16rpm_section == 1 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section  = 2;
		}
		else if( flag.u16rpm_section == 2 )
		{

			GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPASET.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 3 ;
		}
		else if( flag.u16rpm_section == 3 )
		{
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section =4 ;
		}
		else if( flag.u16rpm_section == 4 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
			GpioDataRegs.GPASET.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 5 ;
		}
		else if( flag.u16rpm_section == 5 )
		{	

													
			GpioDataRegs.GPACLEAR.bit.GPIO6= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9= 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 6 ;
		}
		else if( flag.u16rpm_section == 6 )
		{	

													
			GpioDataRegs.GPASET.bit.GPIO6 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9= 1;
			GpioDataRegs.GPASET.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 7 ;
		}
		else if( flag.u16rpm_section == 7 )
		{	
										
			GpioDataRegs.GPASET.bit.GPIO6 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;
													//0.9
			flag.u16rpm_section = 0 ;
		}
		else;
		
		counter.u16motor_rpm = 0 ;
	}
	else{
		counter.u16motor_rpm++ ;
	}
	


	




}

void str_reverse(){



	if( counter.u16motor_str >=  200) //  10  == 1000us
	{
		
		
		if( flag.u16str_section == 0  )
		{
			
										
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;

			//counter.u16motor_flower++;
													//0.9
			flag.u16str_section = 1;
		}
		else if( flag.u16str_section == 1 )
		{
			


													
			GpioDataRegs.GPASET.bit.GPIO23 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13= 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;


		//	counter.u16motor_flower++;

													//0.9
			flag.u16str_section = 2;
		}
		else if( flag.u16str_section == 2 )
		{



			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;

			
			//counter.u16motor_flower++;

													//0.9
			flag.u16str_section = 3 ;
		}
		else if( flag.u16str_section == 3 )
		{
			

			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPASET.bit.GPIO26 = 1;



			//counter.u16motor_flower++;

													//0.9
			flag.u16str_section =4 ;
		}
		else if( flag.u16str_section == 4 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
			
			
		//	counter.u16motor_flower++;
													//0.9
			flag.u16str_section = 5 ;
		}
		else if( flag.u16str_section == 5 )
		{	
			
			GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
			GpioDataRegs.GPASET.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;

													
			


			//counter.u16motor_flower++;

													//0.9
			flag.u16str_section = 6 ;
		}
		else if( flag.u16str_section == 6 )
		{	

			GpioDataRegs.GPACLEAR.bit.GPIO23= 1;
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;


			
		//	counter.u16motor_flower++;

													//0.9
			flag.u16str_section = 7 ;
		}
		else if( flag.u16str_section == 7 )
		{	
			GpioDataRegs.GPASET.bit.GPIO23 = 1;	
			GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
			GpioDataRegs.GPASET.bit.GPIO13 = 1;
			GpioDataRegs.GPACLEAR.bit.GPIO26= 1;




		//	counter.u16motor_flower++;

													//0.9
			flag.u16str_section = 0 ;
		}
		else;
		
		counter.u16motor_str = 0 ;
	}
	else{
		counter.u16motor_str++ ;
		}




}
