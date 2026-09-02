/* 1000:0eb7 */

void FUN_1000_0eb7(void)

{
  char *pcVar1;
  int *piVar2;
  undefined1 uVar3;
  char in_CL;
  int in_DX;
  int in_BX;
  int iVar4;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  longdouble in_ST0;
  
  *(char *)(unaff_SI + 0x16) = *(char *)(unaff_SI + 0x11) + *(char *)(unaff_SI + 0x12);
  uVar3 = *(undefined1 *)(unaff_SI + 0x15);
  *(float *)(in_BX + unaff_SI) = (float)in_ST0;
  iVar4 = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX + *(byte *)(in_BX + unaff_DI));
  pcVar1 = (char *)(iVar4 + unaff_SI + -1);
  *pcVar1 = *pcVar1 + in_CL + CARRY1((byte)in_BX,*(byte *)(in_BX + unaff_DI));
  *(undefined1 *)(unaff_SI + 0x1e) = uVar3;
  piVar2 = (int *)(iVar4 + unaff_SI + -1);
  *piVar2 = *piVar2 - in_DX;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


