/* 1000:6d44 */

void FUN_1000_6d44(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  undefined2 in_AX;
  uint uVar5;
  byte bVar6;
  undefined1 extraout_AH;
  int iVar7;
  undefined2 *puVar8;
  byte bVar9;
  undefined2 in_DX;
  uint extraout_DX;
  uint uVar10;
  undefined2 uVar11;
  undefined2 extraout_DX_00;
  int in_BX;
  undefined2 *unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar12;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  
  *(undefined2 *)0xc4f6 = in_AX;
  puVar2 = unaff_SI + 1;
  out(*unaff_SI,in_DX);
  *(byte *)(unaff_SI + 0x11) = *(byte *)(unaff_SI + 0x11) & (byte)in_DX;
  uVar10 = *(uint *)(in_BX + 8);
  uVar5 = *(uint *)(in_BX + 10);
  for (iVar7 = *(int *)0xc4f4; iVar7 != 0; iVar7 = iVar7 + -1) {
    uVar4 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    uVar10 = (uint)(CONCAT12(uVar4 != 0,uVar10) >> 1);
  }
  uVar5 = uVar10 >> 8;
  if ((*(uint *)(in_BX + 8) & *(uint *)0xc4f6) != 0 || (uVar10 & 0xff) != 0) {
    uVar5 = uVar5 + 1;
  }
  if ((uVar5 & 0xff80) != 0) {
    uVar5 = 0x7f;
  }
  uVar10 = *(uint *)((int)unaff_SI + 0x606d);
  *(uint *)((int)unaff_SI + 0x606d) = uVar5;
  bVar9 = 0x50;
  iVar7 = uVar5 - uVar10;
  puVar8 = puVar2;
  if (iVar7 != 0) {
    if (uVar5 < uVar10) {
      pbVar1 = (byte *)(in_BX + (int)puVar2);
      bVar9 = *pbVar1;
      bVar6 = (byte)(uVar10 - 1 >> 8);
      bVar3 = *pbVar1 - bVar6;
      *pbVar1 = bVar3 - (iVar7 != 0);
      uVar10 = (uint)(byte)(*(char *)0xddce + 'P' + (bVar9 < bVar6 || bVar3 < (iVar7 != 0)));
      do {
        *unaff_DI = 0xff;
        unaff_DI = unaff_DI + uVar10;
        puVar8 = (undefined2 *)((int)puVar8 + -1);
      } while (puVar8 != (undefined2 *)0x0);
      in_BX = CONCAT11((char)((uint)(in_BX + 1) >> 8),(byte)(in_BX + 1) | unaff_DI[in_BX + 0x60]);
      puVar8 = unaff_DS;
    }
    else {
      puVar12 = unaff_DI + uVar10 * -0x50;
      FUN_1000_4b82();
      do {
        *puVar12 = 0x5a;
        puVar12 = puVar12 + -extraout_DX;
        iVar7 = iVar7 + -1;
        uVar10 = extraout_DX;
      } while (iVar7 != 0);
    }
    bVar9 = (byte)uVar10;
    in_BX = in_BX + 0x16;
  }
  *(char *)((int)unaff_SI + 0x606d) =
       *(char *)((int)unaff_SI + 0x606d) + CARRY1(bVar9,*(byte *)0xe460);
  uVar11 = 0;
  if (*(int *)(in_BX + 6) != 0) {
    uVar11 = *(undefined2 *)(*(int *)(in_BX + 6) + 6);
  }
  *(undefined2 *)0x8470 = uVar11;
  func_0x0001f552();
  LOCK();
  iVar7 = *(int *)((int)puVar8 + (int)puVar2);
  *(int *)((int)puVar8 + (int)puVar2) = (int)puVar2;
  UNLOCK();
  LOCK();
  *(undefined2 *)((int)puVar8 + iVar7 + 0x14) = extraout_DX_00;
  UNLOCK();
  *(undefined1 *)((int)puVar8 + -0x7b87) = extraout_AH;
  return;
}


