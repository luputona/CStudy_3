#include "StdAfx.h"
#include "StageDynamic.h"
#include "Include.h"

CStageDynamic::CStageDynamic(void) :
m_fAngle(0.f)
{
}

CStageDynamic::CStageDynamic( const OBJINFO& Info ) :
CObj(Info),
m_fAngle(0.f)
{
}


CStageDynamic::~CStageDynamic(void)
{
}

void CStageDynamic::Chase_Move( const OBJINFO& DestInfo )
{
	m_Info.vDir = DestInfo.vPos - m_Info.vPos; //방향 
	
	D3DXVec3Normalize(&m_Info.vDir,&m_Info.vDir);

	m_Info.vPos += m_Info.vDir * 100.f * GET_SINGLE(CTimeMgr)->GetTime();

}

void CStageDynamic::SetDirect( const OBJINFO& DestInfo )
{
	D3DXVECTOR3 vDirection = DestInfo.vPos - m_Info.vPos;

	D3DXVec3Normalize(&vDirection, &vDirection);
	D3DXVec3Normalize(&m_Info.vLook, &m_Info.vLook);

	m_fAngle = acosf(D3DXVec3Dot(&vDirection,&m_Info.vLook));

	if (DestInfo.vPos.y < m_Info.vPos.y)
	{
		m_fAngle = 2 * D3DX_PI - m_fAngle; //예외처리 
	}


}
