/* 1000:9ab5 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_9ab5(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char in_AL;
  byte in_CL;
  int in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 uVar4;
  undefined2 in_stack_00000000;
  
  pcVar1 = (char *)(unaff_BP + unaff_DI + 0xec7);
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 + in_AL;
  if (SCARRY1(cVar2,in_AL) != *pcVar1 < '\0') {
    uVar3 = *(undefined4 *)(in_BX + unaff_SI + 0x80);
    uVar4 = (undefined2)((ulong)uVar3 >> 0x10);
    *(uint *)(unaff_SI + 0x1e3c) = *(uint *)(unaff_SI + 0x1e3c) >> 3;
    pcVar1 = (char *)(in_BX + (int)uVar3 + 0x17);
    *pcVar1 = *pcVar1 >> (in_CL & 0x1f);
    *(int *)0x2eab = in_DX + 0x20;
    *(uint *)(in_BX + -0x4b) = ~*(uint *)(in_BX + -0x4b);
    *(char *)0x6919 = *(char *)0x6919 + ((byte)in_DX ^ *(byte *)(in_BX + unaff_SI + 0x46));
    *(byte *)0xa10 = *(byte *)0xa10 & (byte)((uint)in_BX >> 8);
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


