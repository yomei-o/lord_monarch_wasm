/* 1000:5cef */

uint FUN_1000_5cef(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  char cVar5;
  uint in_AX;
  byte bVar6;
  uint in_CX;
  int iVar7;
  byte in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint uVar8;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  char in_SF;
  char in_OF;
  int in_stack_00000000;
  
  if (in_OF != in_SF) {
    bVar10 = *(int *)0xc4e6 + in_CX < 0x134;
    uVar8 = (*(int *)0xc4e6 + in_CX) - 0x134;
    if ((bVar10 || uVar8 == 0) || (bVar10 = in_CX < uVar8, uVar8 < in_CX)) {
      *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_DL + bVar10;
      out(0xc4,(char)(in_AX & 0xff01));
      iVar7 = uVar8 * 2;
      *(uint *)(iVar7 + -0x4252) = in_AX & 0xff01;
      *(undefined2 *)(iVar7 + -0x3d82) = 0;
      *(undefined2 *)(iVar7 + 0x1212) = 0x8348;
      *(undefined2 *)(unaff_BP + unaff_SI) = 0xc480;
      in_AX = func_0x0001b63b();
    }
    return in_AX;
  }
  do {
    bVar6 = (byte)(in_AX >> 8);
    bVar10 = (in_AX & 0x100) != 0;
    cVar5 = -(bVar6 & 1);
    in_AX = CONCAT11(bVar6 >> 1,cVar5);
    out(0x7e,cVar5);
    in_CX = in_CX - 1;
  } while (in_CX != 0);
  pbVar1 = (byte *)(in_BX + unaff_SI + 2);
  bVar6 = *pbVar1;
  bVar2 = *pbVar1;
  *pbVar1 = (bVar2 - in_DL) - bVar10;
  *(char *)(in_BX + unaff_SI) =
       (*(char *)(in_BX + unaff_SI) + '0') - (bVar6 < in_DL || (byte)(bVar2 - in_DL) < bVar10);
  bVar6 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar6 ^ 1;
  out(0xa6,bVar6 ^ 1);
  puVar9 = (undefined2 *)0x648c;
  iVar7 = 0x480;
  do {
    LOCK();
    uVar3 = puVar9[0x480];
    puVar9[0x480] = *puVar9;
    UNLOCK();
    puVar4 = puVar9;
    puVar9 = puVar9 + 1;
    *puVar4 = uVar3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return in_stack_00000000 + 1;
}


