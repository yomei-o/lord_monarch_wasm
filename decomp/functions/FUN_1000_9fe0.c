/* 1000:9fe0 */

void FUN_1000_9fe0(void)

{
  uint *puVar1;
  int unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  undefined2 unaff_SS;
  
  puVar1 = (uint *)(unaff_BP + unaff_SI + 0x811);
  *puVar1 = *puVar1 ^ unaff_DI;
  func_0x0001feed();
  FUN_1000_8844();
  FUN_1000_8903();
  FUN_1000_3716();
  FUN_1000_3511();
  FUN_1000_34f7();
  return;
}


