#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "stdint.h"

#define CH_1_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)
#define CH_1_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)

#define CH_2_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define CH_2_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

#define CH_3_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET)
#define CH_3_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)

#define CH_4_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET)
#define CH_4_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET)

#define CH_5_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET)
#define CH_5_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET)

#define CH_6_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET)
#define CH_6_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET)

#define CH_7_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET)
#define CH_7_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET)

#define CH_8_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET)
#define CH_8_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET)

#define CH_9_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET)
#define CH_9_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET)

#define CH_10_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET)
#define CH_10_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET)

#define CH_11_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET)
#define CH_11_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET)

#define CH_12_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET)
#define CH_12_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET)

#define CH_13_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET)
#define CH_13_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET)

#define CH_14_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET)
#define CH_14_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET)

#define CH_15_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET)
#define CH_15_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET)

#define CH_16_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET)
#define CH_16_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET)

#define CH_17_ON  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)
#define CH_17_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET)

#define CH_18_ON  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET)
#define CH_18_OFF  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET)

#define CH_19_ON  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET)
#define CH_19_OFF  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET)

#define CH_20_ON  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET)
#define CH_20_OFF  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET)

#define CH_21_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET)
#define CH_21_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET)

#define CH_22_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET)
#define CH_22_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET)

#define CH_23_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET)
#define CH_23_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET)

#define CH_24_ON  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET)
#define CH_24_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET)

void Turn_On_All_Led(void);
void Turn_Off_All_Led(void);
void turn_on_one_channel_from_right_to_left(uint8_t numberOfRepeat);
void turn_off_one_channel_from_right_to_left(uint8_t numberOfRepeat);
void turn_on_only_one_channel_from_right_to_left(uint8_t numberOfRepeat);
void turn_off_only_one_channel_from_right_to_left(uint8_t numberOfRepeat);
void turn_on_two_channel_from_between_to_beside(uint8_t numberOfRepeat);
void turn_off_two_channel_from_between_to_beside(uint8_t numberOfRepeat);
void turn_on_two_channel_from_beside_to_between(uint8_t numberOfRepeat);
void turn_off_two_channel_from_beside_to_between(uint8_t numberOfRepeat);
void blink_interleaved(uint8_t numberOfRepeat);
void blink_all(uint8_t numberOfRepeat);

extern uint16_t Speed;

#endif /* _EFFECT_H_ */
