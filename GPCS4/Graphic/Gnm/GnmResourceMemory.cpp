#include "GnmResourceMemory.h"

GnmResourceMemory::GnmResourceMemory()
{
}

GnmResourceMemory::GnmResourceMemory(void* start, uint32_t size, GnmMemoryFlag flag) :
	m_flag(flag),
	m_access(GnmMemoryAccess::None),
	m_accessCount(0)
{
	m_range.start = start;
	m_range.end   = reinterpret_cast<uint8_t*>(start) + size;
}

GnmResourceMemory::~GnmResourceMemory()
{
}

const GnmMemoryRange& GnmResourceMemory::range() const
{
	return m_range;
}

void GnmResourceMemory::setRange(const GnmMemoryRange& range)
{
	m_range = range;
}

GnmMemoryAccess GnmResourceMemory::access() const
{
	return m_access;
}

void GnmResourceMemory::setAccess(GnmMemoryAccess access)
{
	m_access = access;
	++m_accessCount;
}

GnmMemoryFlag GnmResourceMemory::flag() const
{
	return m_flag;
}

void GnmResourceMemory::setFlag(GnmMemoryFlag flag)
{
	m_flag = flag;
}

bool GnmResourceMemory::forceUpdate()
{
	return m_accessCount >= ForceUpdateCount;
}

void GnmResourceMemory::reset()
{
	m_access      = GnmMemoryAccess::None;
	m_accessCount = 0;
}