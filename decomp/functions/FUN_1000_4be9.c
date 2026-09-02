/* 1000:4be9 */

undefined2 __cdecl16near FUN_1000_4be9(void)

{
  undefined2 uVar1;
  byte bVar2;
  undefined1 uVar3;
  uint in_AX;
  undefined2 uVar4;
  char cVar5;
  uint uVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  
  uVar6 = in_AX & 0xff00;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
LAB_1000_4c0d:
  while( true ) {
    do {
      bVar2 = FUN_1000_c8b0();
      bVar2 = bVar2 & (byte)(uVar6 >> 8);
    } while (bVar2 == 0);
    if ((bVar2 & 0x20) != 0) break;
    if (((bVar2 & 0x40) != 0) || ((bVar2 & 3) == 0)) goto LAB_1000_4c9a;
    bVar7 = false;
    if (*(char *)0x32e5 != '\0') goto LAB_1000_4c4f;
    uVar4 = FUN_1000_4ca1();
    if (!bVar7) {
      FUN_1000_0d12();
      if ((char)((uint)uVar4 >> 8) == -1) {
        uVar3 = FUN_1000_9295();
        *(undefined1 *)unaff_DI = uVar3;
        goto LAB_1000_4c0a;
      }
      *unaff_DI = uVar4;
      FUN_1000_727a();
      FUN_1000_4af4();
      FUN_1000_72ad();
    }
  }
  FUN_1000_0d12();
LAB_1000_4c9a:
  return CONCAT11(bVar2,*(undefined1 *)unaff_DI);
LAB_1000_4c4f:
  uVar4 = FUN_1000_4ca1();
  if (!bVar7) {
    uVar1 = *unaff_DI;
    do {
      cVar5 = (char)((uint)uVar4 >> 8);
      if (cVar5 != -1) {
        *(char *)((int)unaff_DI + 1) = cVar5;
      }
      *(char *)unaff_DI = (char)uVar4;
      bVar2 = FUN_1000_c8d8();
      bVar7 = false;
    } while (((bVar2 & 3) != 0) && (uVar4 = FUN_1000_4ca1(), !bVar7));
    uVar4 = *unaff_DI;
    *unaff_DI = uVar1;
    if ((char)((uint)uVar4 >> 8) == *(char *)((int)unaff_DI + 1)) {
      uVar3 = FUN_1000_9295();
      *(undefined1 *)unaff_DI = uVar3;
LAB_1000_4c0a:
      FUN_1000_9239();
    }
    else {
      *unaff_DI = uVar4;
      FUN_1000_727a();
      FUN_1000_4af4();
      FUN_1000_72ad();
    }
  }
  goto LAB_1000_4c0d;
}


