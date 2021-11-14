#include "ShiftReg.h"
#include "stm32f1xx_hal.h"


/***********************************
*              DEFINE              *
***********************************/

#define IC595_CLK_PORT            GPIOB
#define IC595_CLK_PORT_PIN        GPIO_PIN_1
#define IC595_LATCH_PORT          GPIOB
#define IC595_LATCH_PORT_PIN      GPIO_PIN_0
#define IC595_DATA_PORT           GPIOA
#define IC595_DATA_PORT_PIN       GPIO_PIN_7

void ShiftData(unsigned int Data)
{
  unsigned int index;
  unsigned int data = Data;

  HAL_GPIO_WritePin(IC595_CLK_PORT, IC595_CLK_PORT_PIN, \
    (GPIO_PinState)0);
  for (index = 0; index < 8; index++)
  {
    HAL_GPIO_WritePin(IC595_DATA_PORT, IC595_DATA_PORT_PIN, \
      (GPIO_PinState)((data & 0x80u) == 0x80u));
    /** @brief Make a raising edge (↑) */
    HAL_GPIO_WritePin(IC595_CLK_PORT, IC595_CLK_PORT_PIN, \
      (GPIO_PinState)1);
    HAL_GPIO_WritePin(IC595_CLK_PORT, IC595_CLK_PORT_PIN, \
      (GPIO_PinState)0);
    data <<= 1;
  }
}

void ShiftLatch(void)
{
  { /** @brief Make a raising edge (↑) */
    HAL_GPIO_WritePin(IC595_LATCH_PORT, IC595_LATCH_PORT_PIN, \
      (GPIO_PinState)0);
    HAL_GPIO_WritePin(IC595_LATCH_PORT, IC595_LATCH_PORT_PIN, \
      (GPIO_PinState)1);
  }
  HAL_GPIO_WritePin(IC595_LATCH_PORT, IC595_LATCH_PORT_PIN, \
    (GPIO_PinState)0);
}
