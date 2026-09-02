/* 1000:054b */

uint __cdecl16near FUN_1000_054b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  int local_16;
  
  FUN_1000_6b12();
  bVar5 = (byte)*(undefined2 *)&DAT_0000_055c & *(byte *)0x488;
  uVar7 = CONCAT11((char)((uint)*(undefined2 *)&DAT_0000_055c >> 8),bVar5) & 0xff03;
  if ((bVar5 & 3) == 0) {
    return uVar7;
  }
  uVar10 = 0;
  uVar8 = uVar7;
  while( true ) {
    uVar14 = (byte)uVar8 & 1;
    uVar8 = (uint)(byte)((byte)uVar8 >> 1);
    if ((bool)uVar14) break;
    uVar10 = uVar10 + 1;
  }
  FUN_1000_6c3f();
  FUN_1000_69df();
  if (((bool)uVar14) || (FUN_1000_6d3a(), (bool)uVar14)) {
    FUN_1000_0ccc();
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    *(undefined2 *)0x1089 = 0x114;
    FUN_1000_49bb();
    FUN_1000_72ad();
    FUN_1000_c612();
    cVar6 = FUN_1000_4be9();
    uVar15 = 0;
    uVar14 = cVar6 == '\0';
    if (!(bool)uVar14) {
      return uVar7;
    }
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_6822();
    while( true ) {
      FUN_1000_6c3f();
      FUN_1000_69df();
      uVar16 = uVar14;
      if ((!(bool)uVar15) && (FUN_1000_6d3a(), uVar16 = uVar14, !(bool)uVar15)) break;
      FUN_1000_6cb5();
      uVar14 = 1;
      if (!(bool)uVar16) {
        return uVar7;
      }
    }
    while( true ) {
      while( true ) {
        puVar11 = (undefined1 *)*(undefined2 *)0x3e82;
        FUN_1000_6c3f();
        FUN_1000_69df();
        if (!(bool)uVar15) break;
        FUN_1000_6cb5();
        bVar4 = !(bool)uVar14;
        uVar14 = 1;
        if (bVar4) {
          return uVar7;
        }
      }
      puVar13 = (undefined1 *)*(undefined2 *)0x3e82;
      for (iVar9 = 0x20; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar2 = puVar13;
        puVar13 = puVar13 + 1;
        puVar1 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar2 = *puVar1;
      }
      FUN_1000_6a55();
      if (!(bool)uVar15) break;
      FUN_1000_6cb5();
      if (!(bool)uVar14) {
        return uVar7;
      }
    }
    while( true ) {
      FUN_1000_7c9e();
      FUN_1000_4a4d();
      FUN_1000_72ad();
      FUN_1000_6c3f();
      FUN_1000_69df();
      if (!(bool)uVar15) break;
      FUN_1000_6cb5();
      bVar4 = !(bool)uVar14;
      uVar14 = 1;
      if (bVar4) {
        return uVar7;
      }
    }
    pbVar12 = (byte *)(*(int *)0x3e82 + 0x140);
    iVar9 = 0xb6;
    do {
      if (*pbVar12 == 0) break;
      uVar15 = *pbVar12 < 0xe5;
      uVar14 = *pbVar12 == 0xe5;
      if (!(bool)uVar14) {
        do {
          FUN_1000_6c3f();
          FUN_1000_687e();
          if (!(bool)uVar15) {
            local_16 = *(int *)0x3e94;
            FUN_1000_6f4b();
            FUN_1000_68bb();
            if (!(bool)uVar15) break;
          }
          FUN_1000_6cb5();
        } while ((bool)uVar14);
        do {
          uVar16 = uVar14;
          FUN_1000_6c3f();
          FUN_1000_6916();
          if ((!(bool)uVar15) && (FUN_1000_694f(), !(bool)uVar15)) {
            iVar3 = *(int *)0x3e94;
            *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(local_16 + 0x16);
            *(undefined2 *)(iVar3 + 0x18) = *(undefined2 *)(local_16 + 0x18);
            FUN_1000_69c2();
            if (!(bool)uVar15) break;
          }
          FUN_1000_6cb5();
          uVar14 = 1;
        } while ((bool)uVar16);
      }
      pbVar12 = pbVar12 + 0x20;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
  }
  else {
    FUN_1000_0ccc();
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_72ad();
    FUN_1000_c612();
  }
  FUN_1000_c90f();
  *(uint *)&DAT_0000_3474 = uVar10;
  *(uint *)&DAT_0000_3476 = uVar10;
  *(uint *)&DAT_0000_3478 = uVar10;
  *(uint *)&DAT_0000_347a = uVar10;
  *(uint *)&DAT_0000_347c = uVar10 ^ 1;
  FUN_1000_633b();
  return uVar7;
}


