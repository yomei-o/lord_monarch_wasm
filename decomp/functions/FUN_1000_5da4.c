/* 1000:5da4 */

/* WARNING: Instruction at (ram,0x00015db6) overlaps instruction at (ram,0x00015db4)
    */

undefined4 FUN_1000_5da4(void)

{
  byte bVar1;
  int in_CX;
  int iVar2;
  undefined2 in_DX;
  uint uVar3;
  byte bVar4;
  int in_BX;
  uint unaff_BP;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *in_ESI;
  undefined2 uVar8;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte *unaff_DS;
  undefined1 in_CF;
  undefined1 in_SF;
  undefined2 in_stack_00000008;
  undefined2 in_stack_0000000c;
  
  do {
    if ((bool)in_SF) {
code_r0x00015dba:
      bVar4 = 0;
      do {
        out(0xa8,bVar4);
        uVar3 = 0xae;
        iVar2 = 3;
        do {
          pbVar6 = (byte *)in_ESI;
          in_ESI = (byte *)ZEXT24(pbVar6 + 1);
          bVar1 = (byte)((uint)(byte)((*pbVar6 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
          out(uVar3,bVar1);
          uVar3 = uVar3 - 2;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 0x10);
      bVar4 = (byte)uVar3;
      *(char *)0xe432 = *(char *)0xe432 + bVar4 + CARRY1(bVar1,bVar4);
      bVar4 = ~(byte)((uint)(byte)(bVar1 + bVar4) / (uVar3 & 0xff));
      return CONCAT22(uVar3,CONCAT11(bVar4,bVar4));
    }
    pbVar5 = (byte *)in_ESI;
    pbVar6 = pbVar5 + 1;
    uVar8 = (undefined2)((ulong)in_ESI >> 0x10);
    bVar4 = *pbVar5;
    out(0xa9,bVar4);
    bVar1 = (byte)((uint)in_DX >> 8);
    in_DX = CONCAT11(bVar1,(char)in_DX + '\x01');
    in_CX = in_CX + -1;
    if (in_CX == 0) {
      LOCK();
      bVar4 = pbVar6[unaff_BP];
      pbVar6[unaff_BP] = bVar1;
      UNLOCK();
      unaff_DI[0x2b] = unaff_DI[0x2b] + bVar4;
      in_ESI = (byte *)0x3e20;
      goto code_r0x00015dba;
    }
    if ((bool)in_CF) {
      while( true ) {
        pbVar6[in_BX + 2] = pbVar6[in_BX + 2] | bVar4;
        bVar4 = *pbVar6;
        pbVar6[in_BX + 0x1f] = pbVar6[in_BX + 0x1f] + bVar4;
        *unaff_DI = bVar4;
        in_BX = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + '\x01');
        in_CX = in_CX + -1;
        if (in_CX == 0) break;
        pbVar6 = (byte *)0x2e10;
        *(byte *)(in_BX + 0x2e10) = *(byte *)(in_BX + 0x2e10) & (byte)in_CX;
        *(uint *)(unaff_DS + unaff_BP + 0x8aa) = *(uint *)(unaff_DS + unaff_BP + 0x8aa) & unaff_BP;
        bVar4 = bVar4 - 0x18 & 0xf;
        out(0xae,bVar4);
        unaff_DI = unaff_DS;
      }
      return CONCAT22(in_stack_00000008,in_stack_0000000c);
    }
    pbVar7 = (byte *)CONCAT22(uVar8,pbVar5 + 3);
    out(*(undefined2 *)pbVar6,in_DX);
    in_CF = CARRY1(*pbVar7,bVar4 + 1);
    *pbVar7 = *pbVar7 + bVar4 + 1;
    in_SF = (char)*pbVar7 < '\0';
    in_ESI = (byte *)CONCAT22(uVar8,pbVar5 + 4);
    out(0xa9,pbVar5[3]);
  } while( true );
}


