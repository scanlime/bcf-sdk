#include <bc_cy8cmbr3102.h>

static void _bc_cy8cmbr3102_button_init(bc_button_t *self);

static int _bc_cy8cmbr3102_button_get_input(bc_button_t *self);

// TODO Interrupt should be implemented (current consumption is too high)

const bc_button_driver_t *bc_cy8cmbr3102_get_button_driver()
{
    static const bc_button_driver_t bc_cy8cmbr3102_button_driver =
            {
                    .init = _bc_cy8cmbr3102_button_init,
                    .get_input = _bc_cy8cmbr3102_button_get_input,
            };

    return &bc_cy8cmbr3102_button_driver;
}

static void _bc_cy8cmbr3102_button_init(bc_button_t *self)
{
    if (self->_channel.virtual == BC_I2C_I2C0)
    {
        bc_i2c_init(BC_I2C_I2C0, BC_I2C_SPEED_400_KHZ);
    }
    else
    {
        bc_i2c_init(BC_I2C_I2C1, BC_I2C_SPEED_400_KHZ);
    }
}

static int _bc_cy8cmbr3102_button_get_input(bc_button_t *self)
{
    uint16_t count;

    if (self->_channel.virtual == BC_I2C_I2C0)
    {
        while (!bc_i2c_memory_read_16b(BC_I2C_I2C0, 0x37, 0xba, &count))
        {
            continue;
        }
    }
    else
    {
        while (!bc_i2c_memory_read_16b(BC_I2C_I2C1, 0x37, 0xba, &count))
        {
            continue;
        }
    }

    if (count > 1000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
