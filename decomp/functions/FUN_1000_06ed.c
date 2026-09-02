/* 1000:06ed */

/* WARNING: Instruction at (ram,0x000106fa) overlaps instruction at (ram,0x000106f9)
    */
/* WARNING: Removing unreachable block (ram,0x00010713) */

undefined2 FUN_1000_06ed(undefined2 param_1,undefined2 param_2)

{
  char *pcVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  undefined1 in_DL;
  char in_DH;
  int iVar7;
  undefined2 *puVar8;
  undefined2 *unaff_BP;
  uint *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *unaff_SI = *unaff_SI ^ 0xffe6;
  iVar2 = (int)unaff_SI + 1;
  *unaff_DI = (char)*unaff_SI;
  iVar7 = 0;
  cVar5 = *(char *)0x32c3;
  if (cVar5 != '\0') {
    *(undefined1 *)0x32cc = 0;
    iVar7 = CONCAT11(in_DL,cVar5 + -1) + 1;
    bVar3 = *(byte *)((int)unaff_BP + iVar2);
    *(undefined1 *)((int)unaff_SI + 0xd) = 0;
    puVar8 = (undefined2 *)&stack0xfffe;
    cVar5 = '\x06';
    do {
      unaff_BP = unaff_BP + -1;
      puVar8 = puVar8 + -1;
      *puVar8 = *unaff_BP;
      cVar5 = cVar5 + -1;
    } while ('\0' < cVar5);
    return CONCAT11((byte)((uint)iVar7 >> 8) ^ bVar3,(char)iVar7);
  }
  uVar4 = *(undefined4 *)((undefined1 *)((int)unaff_BP + (int)(unaff_DI + 1)) + -0x1e);
  iVar6 = (int)uVar4;
  out(0xbb,iVar6);
  pcVar1 = (char *)((int)unaff_BP + (int)(unaff_DI + 1));
  *pcVar1 = *pcVar1 + in_DH;
  *(char *)((int)unaff_BP + iVar2) = *(char *)((int)unaff_BP + iVar2) >> 7;
  *(char *)((int)unaff_BP + iVar2) = *(char *)((int)unaff_BP + iVar2) << 1;
  do {
    if ((char)uVar4 != *(char *)(iVar7 + 0x32d0)) {
      *(char *)(iVar7 + 0x32d0) = *(char *)(iVar7 + 0x32d0) + -1;
    }
    iVar7 = iVar7 + -1;
  } while (-1 < iVar7);
  if (iVar6 != *(int *)0x32d8) {
    *(int *)0x32d8 = *(int *)0x32d8 + -1;
  }
  *(int *)0x32da = *(int *)0x32da + -1;
  if ((*(int *)0x32e0 != 0) && ((*(uint *)0x32da & 1) == 0)) {
    cVar5 = *(char *)0x3e4e;
    if (cVar5 < '\0') {
      cVar5 = cVar5 + '\x01';
      if (-1 < cVar5) {
        cVar5 = '\x0f';
      }
    }
    else {
      cVar5 = cVar5 + -1;
      if (cVar5 < '\0') {
        cVar5 = -0x10;
      }
    }
    *(char *)0x3e4e = cVar5;
  }
  FUN_1000_72f8();
  FUN_1000_743c();
  out(0,0x20);
  out(100,0x20);
  return param_2;
}


