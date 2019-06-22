#include "TMCStepper.h"
using namespace TMC2209_n;

uint32_t TMC2209Stepper::IOIN() {
	return read(TMC2209_n::IOIN_t::address);
}
bool TMC2209Stepper::enn()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.enn;		}
bool TMC2209Stepper::ms1()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.ms1;		}
bool TMC2209Stepper::ms2()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.ms2;		}
bool TMC2209Stepper::diag()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.diag;		}
bool TMC2209Stepper::pdn_uart()		{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.pdn_uart;	}
bool TMC2209Stepper::step()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.step;		}
bool TMC2209Stepper::spread_en()	{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.spread_en;}
bool TMC2209Stepper::dir()			{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.dir;		}
uint8_t TMC2209Stepper::version() 	{ TMC2209_n:IOIN_t r{0}; r = IOIN(); return r.version;	}

void TMC2209Stepper::push() {
	IHOLD_IRUN(IHOLD_IRUN_register.sr);
	TPOWERDOWN(TPOWERDOWN_register.sr);
	TPWMTHRS(TPWMTHRS_register.sr);
	GCONF(GCONF_register.sr);
	SLAVECONF(SLAVECONF_register.sr);
	VACTUAL(VACTUAL_register.sr);
	CHOPCONF(CHOPCONF_register.sr);
	PWMCONF(PWMCONF_register.sr);
	TCOOLTHRS(TCOOLTHRS_register.sr);
}

void TMC2209Stepper::SGTHRS(uint8_t input) {
	SGTHRS_register = input;
	write(SGTHRS_register.address, SGTHRS_register.sr);
}
uint8_t TMC2209Stepper::SGTHRS() {
	return SGTHRS_register.sr;
}

// W: TCOOLTHRS
uint32_t TMC2209Stepper::TCOOLTHRS() { return TCOOLTHRS_register.sr; }
void TMC2209Stepper::TCOOLTHRS(uint32_t input) {
  TCOOLTHRS_register = input;
  write(TCOOLTHRS_register.address, TCOOLTHRS_register.sr);
}

uint16_t TMC2209Stepper::SG_RESULT() {
	return read(SG_RESULT_t::address);
}
