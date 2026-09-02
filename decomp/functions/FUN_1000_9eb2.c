/* 1000:9eb2 */

/* WARNING: Instruction at (ram,0x00019ee3) overlaps instruction at (ram,0x00019ee2)
    */

void FUN_1000_9eb2(void)

{
  byte *pbVar1;
  int iVar2;
  undefined2 in_DX;
  byte extraout_DH;
  undefined2 extraout_DX;
  int in_BX;
  byte bVar3;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uStack0003;
  undefined2 uStack0005;
  undefined2 uStack0007;
  undefined2 uStack0009;
  undefined2 uStack000b;
  undefined2 uStack000d;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI + -0x2b);
  *pbVar1 = *pbVar1 ^ (byte)((uint)in_DX >> 8);
  *(char *)(unaff_BP + 0x30a8) = *(char *)(unaff_BP + 0x30a8) + (char)((uint)in_BX >> 8);
  func_0x00013b7b();
  iVar2 = func_0x0001ee23();
  pbVar1 = (byte *)(unaff_BP + unaff_SI);
  bVar3 = (byte)iVar2;
  *pbVar1 = *pbVar1 & bVar3;
  if ((char)*pbVar1 < '\0') {
    func_0x0001ee41();
  }
  else {
    *(byte *)0x5a36 = bVar3;
    *(byte *)0x5a37 = bVar3;
    pbVar1 = (byte *)(in_BX + unaff_SI + -0x6a);
    *pbVar1 = *pbVar1 | (byte)in_BX;
    unaff_SI = 0x3c5;
    *(int *)0x60bc = iVar2 + -1;
    *(byte *)(unaff_BP + 0x3c5) = *(byte *)(unaff_BP + 0x3c5) | extraout_DH;
  }
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & (byte)in_BX;
  *(byte *)(in_BX + 0x5a2e) = *(byte *)(in_BX + 0x5a2e) ^ (byte)((uint)in_BX >> 8);
  uStack0003 = 0x9ef5;
  func_0x00013b71();
  uStack0005 = 0x9ef8;
  func_0x00019b19();
  bVar3 = (byte)((uint)in_BX >> 8);
  iVar2 = CONCAT11(bVar3,(byte)in_BX & *(byte *)(unaff_BP + -0x3e42));
  *(byte *)(iVar2 + 0x642e) = *(byte *)(iVar2 + 0x642e) ^ bVar3;
  uStack0007 = 0x9f05;
  func_0x00013b6f();
  bVar3 = (byte)((uint)iVar2 >> 8);
  uStack0009 = 0x9f08;
  func_0x0001ad17();
  bVar3 = bVar3 & (byte)((uint)*(undefined2 *)0xe0be >> 8);
  uStack000b = 0x9f15;
  func_0x00013b6d();
  uStack000d = 0x9f18;
  FUN_1000_3815();
  out(CONCAT11((byte)((uint)extraout_DX >> 8) | bVar3,
               (char)extraout_DX - *(char *)(unaff_BP + 0x3103)),(char)unaff_BP);
  uStack000d = 0x9f2f;
  FUN_1000_3539();
  return;
}


