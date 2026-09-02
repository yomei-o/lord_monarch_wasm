/* 1000:6e44 */

/* WARNING: Instruction at (ram,0x00016e47) overlaps instruction at (ram,0x00016e44)
    */

uint FUN_1000_6e44(void)

{
  byte bVar1;
  undefined1 uVar2;
  int in_CX;
  undefined1 *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    bVar1 = *(byte *)0x3482;
    out(0xa6,bVar1 ^ 1);
    uVar2 = *unaff_SI;
    unaff_SI[0x2488] = unaff_SI[0x2488] + (char)in_CX;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    unaff_SI = &stack0x000c + (int)unaff_SI;
  }
  return CONCAT11(uVar2,bVar1) ^ 1;
}


