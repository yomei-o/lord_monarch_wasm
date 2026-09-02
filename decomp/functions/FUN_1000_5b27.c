/* 1000:5b27 */

void FUN_1000_5b27(void)

{
  byte *pbVar1;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar2;
  undefined2 uStack0006;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + 0x5b);
  bVar2 = false;
  *pbVar1 = *pbVar1 ^ (byte)in_BX;
  uStack0006 = 0x5b31;
  FUN_1000_5b82();
  if (!bVar2) {
    FUN_1000_5be1();
  }
  return;
}


