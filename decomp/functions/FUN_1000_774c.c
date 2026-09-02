/* 1000:774c */

undefined4 FUN_1000_774c(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int in_BX;
  undefined2 unaff_DS;
  undefined2 in_stack_00000010;
  undefined2 in_stack_00000014;
  
  func_0x0001dc56();
  FUN_1000_2f08();
  func_0x0001dc75();
  iVar2 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8();
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
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_stack_00000010,in_stack_00000014);
}


