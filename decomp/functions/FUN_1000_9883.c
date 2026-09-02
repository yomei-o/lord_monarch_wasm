/* 1000:9883 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0001985d) */

void FUN_1000_9883(void)

{
  byte *pbVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined1 uVar4;
  uint uVar5;
  byte bVar6;
  int extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    FUN_1000_5f1a();
    uVar5 = FUN_1000_3721();
    bVar6 = 0x52;
    LOCK();
    uVar4 = *(undefined1 *)(unaff_BP + 0x45be);
    *(undefined1 *)(unaff_BP + 0x45be) = (char)in_BX;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),uVar4);
    UNLOCK();
    puVar2 = (uint *)(unaff_SI + in_BX);
    *puVar2 = *puVar2 & uVar5;
    if (*puVar2 != 0) break;
    func_0x00013993();
    FUN_1000_5e88();
    func_0x00018b75();
    pbVar1 = unaff_SI + 8;
    unaff_SI = (byte *)0x793d;
    *(uint *)(in_BX + 0x793d) = *(uint *)(in_BX + 0x793d) & extraout_DX - *(int *)pbVar1;
  }
  FUN_1000_5f13();
  FUN_1000_371a();
  in(extraout_DX_00);
  pbVar3 = unaff_SI;
  *pbVar3 = *pbVar3 << (bVar6 & 7) | *pbVar3 >> 8 - (bVar6 & 7);
  uVar4 = in(extraout_DX_00);
  *unaff_DI = uVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


