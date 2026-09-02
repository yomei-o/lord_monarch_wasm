/* 1000:7056 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_7056(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  undefined2 in_AX;
  int iVar7;
  int iVar8;
  byte bVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 unaff_SS;
  longdouble in_ST0;
  undefined1 auStack_5 [2];
  
  puVar11 = (undefined2 *)0xc8e;
  puVar10 = (undefined2 *)0x8000;
  iVar7 = 0x130;
  do {
    for (iVar8 = 0x16; iVar8 != 0; iVar8 = iVar8 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    puVar11 = puVar11 + 0x12;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar10[0x24] = (int)in_ST0;
  iVar7 = puVar10[2];
  iVar8 = puVar10[3];
  uVar1 = puVar10[1];
  pbVar6 = (byte *)*puVar10;
  bVar4 = *pbVar6;
  *(byte *)0x0 = bVar4;
  bVar5 = pbVar6[-0x8000];
  *(byte *)0x1 = bVar5;
  *(undefined1 **)(pbVar6 + iVar8) = auStack_5 + *(int *)(pbVar6 + iVar8);
  bVar9 = (byte)iVar7 | pbVar6[iVar8];
  if (iVar7 == 1 || bVar9 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  LOCK();
  *(int *)pbVar6 = iVar8;
  UNLOCK();
  out(CONCAT11((char)((uint)iVar7 >> 8),bVar9),CONCAT11(bVar4 & bVar5,bVar5 + 0x8b));
  (pbVar6 + 0x1a)[0] = 2;
  (pbVar6 + 0x1a)[1] = 0;
  *(undefined1 *)0xb802 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


