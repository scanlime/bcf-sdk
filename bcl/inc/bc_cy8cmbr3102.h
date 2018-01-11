#ifndef _BC_CY8CMBR3102_H
#define _BC_CY8CMBR3102_H

#include <bc_common.h>
#include <bc_i2c.h>
#include <bc_button.h>

//! @brief Get cy8cmbr3102 button driver
//! @return Driver for cy8cmbr3102 as a button

const bc_button_driver_t *bc_cy8cmbr3102_get_button_driver();

#endif /* _BC_CY8CMBR3102_H */
