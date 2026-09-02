/* 1000:46ef */

/* WARNING: Instruction at (ram,0x00014727) overlaps instruction at (ram,0x00014726)
    */

void FUN_1000_46ef(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  uint in_AX;
  byte bVar10;
  undefined2 in_CX;
  byte bVar11;
  undefined2 extraout_DX;
  int *in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  ulong uVar13;
  byte *pbStack_c;
  int iStack_a;
  undefined2 uStack_6;
  
  do {
    puVar5 = (undefined1 *)*(undefined2 *)0x36a2;
    puVar1 = (uint *)(unaff_SI + unaff_BP);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - in_AX;
    bVar12 = 0xefdb < in_AX || CARRY2(in_AX + 0x1024,(uint)(uVar3 < in_AX));
    bVar8 = (char)(in_AX + 0x1024) + (uVar3 < in_AX);
    bVar7 = bVar8 + 0xa8;
    bVar9 = bVar7 - bVar12;
    bVar11 = (byte)((uint)in_CX >> 8);
    bVar10 = (byte)in_CX;
    iVar6 = *in_BX;
    FUN_1000_6153();
    func_0x00017611();
    *(undefined2 *)0x89a2 = 0x132;
    pbVar2 = unaff_SI;
    *pbVar2 = *pbVar2 >> (bVar10 & 7) | *pbVar2 << 8 - (bVar10 & 7);
    FUN_1000_4693();
    func_0x0001b778();
    uVar4 = in(extraout_DX);
    *puVar5 = uVar4;
    *(uint *)((byte *)((int)in_BX + (int)unaff_SI) + 0x7440) =
         *(int *)((byte *)((int)in_BX + (int)unaff_SI) + 0x7440) -
         (unaff_BP + iVar6 +
         (uint)(bVar11 < bVar9 || (byte)(bVar11 - bVar9) < (bVar8 < 0x58 || bVar7 < bVar12)));
    unaff_ES = *(undefined2 *)(byte *)((int)in_BX + (int)unaff_SI);
    in_CX = 0x4701;
    in_BX = (int *)CONCAT11((char)((uint)uStack_6 >> 8),(char)uStack_6 + 'G');
    do {
      thunk_FUN_1000_47c8();
      uVar13 = func_0x0001b68c();
    } while ((uVar13 & 0xf) != 0);
    *(undefined2 *)0x3bdc = (int)(uVar13 >> 0x10);
    *(undefined1 *)0x3289 = 0x2f;
    in_AX = (uint)uVar13 & 0xff0f | 0xc7ef;
    unaff_BP = iStack_a;
    unaff_SI = pbStack_c;
  } while( true );
}


