/* 1000:2ea2 */

char FUN_1000_2ea2(void)

{
  uint *puVar1;
  uint uVar2;
  char in_AL;
  int unaff_BP;
  uint unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  int in_stack_00000000;
  
  if (!in_CF) {
    return in_AL;
  }
  uVar2 = *(uint *)(in_stack_00000000 + 0x1287);
  puVar1 = (uint *)(unaff_BP + unaff_SI + 1);
  *puVar1 = *puVar1 | unaff_SI;
  return (in_AL + '\x18') - (uVar2 < 0x5c);
}


