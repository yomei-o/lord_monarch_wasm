/* 1000:4db2 */

uint __cdecl16near FUN_1000_4db2(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined2 unaff_DS;
  
  uVar2 = *(undefined2 *)0x32f0;
  uVar3 = *(undefined2 *)0x32ee;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
  *(undefined2 *)0x32ee = 9;
  *(undefined2 *)0x32f0 = 0x3c;
LAB_1000_4ddb:
  do {
    bVar4 = FUN_1000_c8b0();
  } while ((bVar4 & 0x6f) == 0);
  if ((bVar4 & 0x20) != 0) {
    FUN_1000_0d12();
LAB_1000_4e39:
    uVar1 = *(undefined1 *)0x3bee;
    *(undefined2 *)0x32ee = uVar3;
    *(undefined2 *)0x32f0 = uVar2;
    return CONCAT11(bVar4,uVar1) & 0x6fff;
  }
  if ((bVar4 & 0x40) != 0) goto LAB_1000_4e39;
  if ((bVar4 & 2) != 0) goto LAB_1000_4dfc;
  if ((bVar4 & 4) == 0) {
    if ((bVar4 & 8) != 0) {
      if ((*(byte *)0x3bee & 1) == 0) {
        bVar4 = *(byte *)0x3bee | 1;
        goto LAB_1000_4e26;
      }
      goto LAB_1000_4ddb;
    }
    if (((bVar4 & 1) == 0) || (bVar4 = *(byte *)0x3bee - 2, *(byte *)0x3bee < 2))
    goto LAB_1000_4ddb;
  }
  else {
    if ((*(byte *)0x3bee & 1) == 0) goto LAB_1000_4ddb;
    bVar4 = *(byte *)0x3bee & 0xfe;
  }
LAB_1000_4e26:
  *(byte *)0x3bee = bVar4;
  FUN_1000_4d4a();
  goto LAB_1000_4ddb;
LAB_1000_4dfc:
  bVar4 = *(char *)0x3bee + 2;
  if (0xd < bVar4) goto LAB_1000_4ddb;
  goto LAB_1000_4e26;
}


