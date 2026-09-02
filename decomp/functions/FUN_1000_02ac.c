/* 1000:02ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000103a0) overlaps instruction at (ram,0x0001039f)
    */
/* WARNING: Removing unreachable block (ram,0x000102f4) */
/* WARNING: Removing unreachable block (ram,0x00010312) */
/* WARNING: Removing unreachable block (ram,0x00010314) */
/* WARNING: Removing unreachable block (ram,0x00010319) */
/* WARNING: Removing unreachable block (ram,0x0001034f) */
/* WARNING: Removing unreachable block (ram,0x00010377) */
/* WARNING: Removing unreachable block (ram,0x00010387) */
/* WARNING: Removing unreachable block (ram,0x00010316) */
/* WARNING: Removing unreachable block (ram,0x0001039f) */
/* WARNING: Removing unreachable block (ram,0x000103a6) */
/* WARNING: Removing unreachable block (ram,0x000103a8) */
/* WARNING: Removing unreachable block (ram,0x000103b3) */
/* WARNING: Removing unreachable block (ram,0x000103be) */
/* WARNING: Removing unreachable block (ram,0x00010400) */
/* WARNING: Removing unreachable block (ram,0x000103c0) */
/* WARNING: Removing unreachable block (ram,0x000103f7) */
/* WARNING: Removing unreachable block (ram,0x000103c7) */
/* WARNING: Removing unreachable block (ram,0x000103d8) */
/* WARNING: Removing unreachable block (ram,0x000103ee) */
/* WARNING: Removing unreachable block (ram,0x000103f8) */
/* WARNING: Removing unreachable block (ram,0x000103ff) */
/* WARNING: Removing unreachable block (ram,0x0001040b) */
/* WARNING: Removing unreachable block (ram,0x0001041c) */
/* WARNING: Removing unreachable block (ram,0x00010420) */
/* WARNING: Removing unreachable block (ram,0x0001042a) */
/* WARNING: Removing unreachable block (ram,0x0001042d) */
/* WARNING: Removing unreachable block (ram,0x00010394) */
/* WARNING: Removing unreachable block (ram,0x000102ec) */
/* WARNING: Removing unreachable block (ram,0x00010396) */
/* WARNING: Removing unreachable block (ram,0x000103e1) */

undefined4 FUN_1000_02ac(undefined2 *param_1,undefined2 param_2,int param_3)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  byte bVar3;
  int in_BX;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_GS;
  byte *in_stack_00000000;
  
  pbVar1 = in_stack_00000000;
  *pbVar1 = *pbVar1 & (byte)in_AX;
  if ('\0' < (char)*pbVar1) {
    in_stack_00000000[in_BX] = in_stack_00000000[in_BX] + (char)((uint)in_AX >> 8);
    bVar3 = (byte)((uint)in_DX >> 8);
    in_stack_00000000[in_BX] = in_stack_00000000[in_BX] ^ bVar3;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      puVar2 = param_1;
      param_1 = param_1 + 1;
      *puVar2 = in_AX;
    }
    *(undefined1 *)0x3c08 = 0;
    *(undefined2 *)0x3bc2 = 0xffff;
    *(char *)(in_BX + 0x10) = *(char *)(in_BX + 0x10) + bVar3;
    *(char *)(in_BX + (int)param_1) = *(char *)(in_BX + (int)param_1) + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT22(in_DX,in_AX);
}


