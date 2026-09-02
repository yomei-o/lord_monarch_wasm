/* 1000:509f */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_509f(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined2 in_AX;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint in_CX;
  undefined2 in_DX;
  byte *in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar7;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar8;
  byte in_AF;
  
  bVar8 = 9 < ((byte)in_AX & 0xf) | in_AF;
  uVar4 = CONCAT11((char)((uint)in_AX >> 8) - bVar8 & *in_BX,(byte)in_AX + bVar8 * -6) & 0xff0f;
  uVar5 = uVar4 + 0x373;
  puVar1 = (uint *)(unaff_SI + 1);
  uVar3 = (uint)(0xfc8c < uVar4);
  uVar4 = *puVar1;
  uVar2 = *puVar1;
  *puVar1 = uVar2 + uVar5 + uVar3;
  iVar7 = unaff_SI + 2;
  puVar1 = (uint *)(unaff_BP + iVar7);
  uVar3 = (uint)(CARRY2(uVar4,uVar5) || CARRY2(uVar2 + uVar5,uVar3));
  uVar4 = *puVar1;
  uVar2 = *puVar1;
  *puVar1 = uVar2 + uVar5 + uVar3;
  *(undefined1 *)(unaff_BP + iVar7) = (char)in_CX;
  *(int *)(unaff_BP + iVar7) =
       *(int *)(unaff_BP + iVar7) + uVar5 +
       (uint)(CARRY2(uVar4,uVar5) || CARRY2(uVar2 + uVar5,uVar3));
  uVar6 = in(in_DX);
  bVar8 = (byte)uVar6;
  *unaff_DI = bVar8;
  puVar1 = (uint *)(CONCAT11(7,(char)in_BX) + iVar7);
  uVar4 = (uint)((byte)(bVar8 - 0x18) < 0x12 || (byte)(bVar8 - 0x2a) < (0x17 < bVar8));
  bVar8 = CARRY2(*puVar1,in_CX) || CARRY2(*puVar1 + in_CX,uVar4);
  *puVar1 = *puVar1 + in_CX + uVar4;
  FUN_1000_6bca();
  *(uint *)0x87c = *(uint *)0x87c << 1 | (uint)bVar8;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


