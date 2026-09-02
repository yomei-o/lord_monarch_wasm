/* 1000:7c45 */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_7c45(void)

{
  uint uVar1;
  char in_AL;
  int in_CX;
  int in_DX;
  int in_BX;
  byte *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(unaff_SI + in_BX + -0x46);
  unaff_SI[in_BX] = unaff_SI[in_BX] + in_AL;
  do {
    if ((*unaff_SI & 0x80) != 0) break;
    unaff_SI = unaff_SI + in_DX;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return CONCAT22(((undefined2 *)((uint)&stack0x0000 ^ uVar1))[2],
                  *(undefined2 *)((uint)&stack0x0000 ^ uVar1));
}


