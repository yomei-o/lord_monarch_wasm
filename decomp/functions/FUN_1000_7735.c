/* 1000:7735 */

undefined4 FUN_1000_7735(void)

{
  byte bVar1;
  uint in_AX;
  int in_CX;
  int iVar2;
  int iVar3;
  uint in_DX;
  uint extraout_DX;
  int in_BX;
  undefined2 unaff_DS;
  undefined4 uVar4;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  if (in_AX < *(uint *)(in_BX + 8)) {
    if (in_CX == 1) {
      FUN_1000_2f02();
      uVar4 = func_0x0001dc6f();
      return uVar4;
    }
    FUN_1000_2f08();
    func_0x0001dc75();
    in_DX = extraout_DX;
  }
  iVar2 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8(iVar2,in_DX);
      bVar1 = *(byte *)(in_BX + -0x2d82);
      if ((bVar1 < 0x30) || (0x5f < bVar1)) {
        if ((bVar1 < 0x20) || (0x2f < bVar1)) {
          if ((bVar1 == 0) || (4 < bVar1)) {
            if ((0x5f < bVar1) && (bVar1 < 0x70)) {
              FUN_1000_78c3();
            }
          }
          else {
            FUN_1000_7885();
          }
        }
        else {
          func_0x0001783a();
        }
      }
      else {
        FUN_1000_77c1();
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    in_DX = (uint)(byte)((char)in_DX + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


