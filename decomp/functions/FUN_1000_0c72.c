/* 1000:0c72 */

void FUN_1000_0c72(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  int in_AX;
  byte in_CL;
  int unaff_BP;
  int *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  undefined1 uVar5;
  byte in_stack_00000000;
  
  *unaff_SI = *unaff_SI + in_AX + (uint)in_CF;
  pcVar1 = (char *)(unaff_BP + unaff_DI + 0x11);
  *pcVar1 = *pcVar1 + in_stack_00000000;
  pbVar2 = (byte *)(unaff_BP + unaff_DI + 0x11);
  uVar5 = CARRY1(*pbVar2,in_stack_00000000);
  *pbVar2 = *pbVar2 + in_stack_00000000;
  FUN_1000_0dcd();
  FUN_1000_0dcd();
  FUN_1000_0dcd();
  *(undefined1 *)0x3b43 = 0;
  bVar4 = (in_CL & 0x1f) % 0x11;
  uVar3 = *(uint *)(unaff_BP + unaff_DI);
  *(uint *)(unaff_BP + unaff_DI) = uVar3 << bVar4 | (uint)(CONCAT12(uVar5,uVar3) >> 0x11 - bVar4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


