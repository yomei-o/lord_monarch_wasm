/* 1000:c7ce */

undefined4 __cdecl16near FUN_1000_c7ce(void)

{
  uint uVar1;
  int iVar2;
  undefined2 in_AX;
  uint uVar3;
  undefined2 in_DX;
  byte bVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  *(undefined1 *)0x32e5 = 0;
  *(byte *)0x32ce = *(byte *)0x32cb | *(byte *)0x32cc;
  bVar4 = *(byte *)0x32e4;
  uVar1 = *(uint *)0x32f0;
  iVar2 = *(int *)0x32ea;
  uVar3 = *(uint *)0x32e6;
  if (uVar3 != 0) {
    if ((int)uVar3 < 0) {
      if (uVar3 < -*(uint *)0x32ee) {
        if (((iVar2 == 0) || (iVar2 < 0)) || (uVar3 = uVar3 + iVar2, (int)uVar3 < 0)) {
          bVar4 = bVar4 | 4;
          bVar5 = CARRY2(uVar3,uVar1);
          uVar3 = uVar3 + uVar1;
          if (!bVar5) {
LAB_1000_c829:
            *(uint *)0x32e6 = uVar3;
            *(undefined2 *)0x32ea = 0;
            goto LAB_1000_c83d;
          }
        }
LAB_1000_c834:
        *(undefined2 *)0x32e6 = 0;
        *(uint *)0x32ea = uVar3;
      }
    }
    else if (*(uint *)0x32ee <= uVar3) {
      if (((iVar2 == 0) || (-1 < iVar2)) || (uVar3 = uVar3 + iVar2, -1 < (int)uVar3)) {
        bVar4 = bVar4 | 8;
        bVar5 = uVar1 <= uVar3;
        uVar3 = uVar3 - uVar1;
        if (bVar5) goto LAB_1000_c829;
      }
      goto LAB_1000_c834;
    }
  }
LAB_1000_c83d:
  iVar2 = *(int *)0x32ec;
  uVar3 = *(uint *)0x32e8;
  if (uVar3 == 0) goto LAB_1000_c892;
  if ((int)uVar3 < 0) {
    if (-*(uint *)0x32ee <= uVar3) goto LAB_1000_c892;
    if (((iVar2 == 0) || (iVar2 < 0)) || (uVar3 = uVar3 + iVar2, (int)uVar3 < 0)) {
      bVar4 = bVar4 | 1;
      bVar5 = CARRY2(uVar3,uVar1);
      uVar3 = uVar3 + uVar1;
      if (!bVar5) {
LAB_1000_c87e:
        *(uint *)0x32e8 = uVar3;
        *(undefined2 *)0x32ec = 0;
        goto LAB_1000_c892;
      }
    }
  }
  else {
    if (uVar3 < *(uint *)0x32ee) goto LAB_1000_c892;
    if (((iVar2 == 0) || (-1 < iVar2)) || (uVar3 = uVar3 + iVar2, -1 < (int)uVar3)) {
      bVar4 = bVar4 | 2;
      bVar5 = uVar1 <= uVar3;
      uVar3 = uVar3 - uVar1;
      if (bVar5) goto LAB_1000_c87e;
    }
  }
  *(undefined2 *)0x32e8 = 0;
  *(uint *)0x32ec = uVar3;
LAB_1000_c892:
  if ((bVar4 != 0) && (*(undefined1 *)0x32e5 = 1, (bVar4 & 0x60) == 0)) {
    *(undefined1 *)0x32d0 = 0;
  }
  *(byte *)0x32ce = *(byte *)0x32ce | bVar4;
  return CONCAT22(in_DX,CONCAT11((char)((uint)in_AX >> 8),*(undefined1 *)0x32ce));
}


