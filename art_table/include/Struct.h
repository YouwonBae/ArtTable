//###########################################################################
//
// filename		:Struct.h
//
// TwinCopter structure header file.
//
// by Choi gi baek (MAZE 16TH)
//
//###########################################################################
// $Release Date: 2012.01.18 $
//###########################################################################

#ifndef __STRUCT_H__
#define __STRUCT_H__

#ifdef __STRUCT__

#undef __STRUCT__
#define __STRUCT_EXT__

#else

#define __STRUCT_EXT__	extern

#endif


#endif

typedef struct counter_variable{

	Uint16 u16motor_str ;
	Uint16 u16motor_rpm;
	Uint16 u16motor_stop;
	Uint16 u16motor_flower;
	Uint16 u16motor_str2;



	
}counter_val;

__STRUCT_EXT__ counter_val counter;

typedef struct flag_variable{

	Uint16 u16str_section ;
	Uint16 u16str_forward ;
	Uint16 u16str_reverse ;


	Uint16 u16rpm_section;
	
}flag_val;

__STRUCT_EXT__ flag_val flag;



