/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpdma.c
  * @brief   This file provides code for the configuration
  *          of the GPDMA instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "gpdma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

DMA_HandleTypeDef handle_GPDMA1_Channel12;

/* GPDMA1 init function */
void MX_GPDMA1_Init(void)
{

  /* USER CODE BEGIN GPDMA1_Init 0 */

  /* USER CODE END GPDMA1_Init 0 */

  /* Peripheral clock enable */
  __HAL_RCC_GPDMA1_CLK_ENABLE();

  /* GPDMA1 interrupt Init */
    HAL_NVIC_SetPriority(GPDMA1_Channel12_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(GPDMA1_Channel12_IRQn);

  /* USER CODE BEGIN GPDMA1_Init 1 */

  /* USER CODE END GPDMA1_Init 1 */
  handle_GPDMA1_Channel12.Instance = GPDMA1_Channel12;
  handle_GPDMA1_Channel12.InitLinkedList.Priority = DMA_HIGH_PRIORITY;
  handle_GPDMA1_Channel12.InitLinkedList.LinkStepMode = DMA_LSM_FULL_EXECUTION;
  handle_GPDMA1_Channel12.InitLinkedList.LinkAllocatedPort = DMA_LINK_ALLOCATED_PORT0;
  handle_GPDMA1_Channel12.InitLinkedList.TransferEventMode = DMA_TCEM_LAST_LL_ITEM_TRANSFER;
  handle_GPDMA1_Channel12.InitLinkedList.LinkedListMode = DMA_LINKEDLIST_CIRCULAR;
  if (HAL_DMAEx_List_Init(&handle_GPDMA1_Channel12) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA_ConfigChannelAttributes(&handle_GPDMA1_Channel12, DMA_CHANNEL_NPRIV) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN GPDMA1_Init 2 */

  /* USER CODE END GPDMA1_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
