#include "trendwndmacro.h"

#include <q3listview.h>

class HMITRENDWND_EXPORT PtrListViewItem : public Q3ListViewItem
{
public:
	enum ItemType
	{
		VoidPtr,
		Axis,
		AxisBase,
		AxisDisp,
		AxisEng,
		Trend,
		TrendBase,
		TrendDrawer
	};
	PtrListViewItem ( Q3ListViewItem * parent, Q3ListViewItem * after );
	PtrListViewItem ( Q3ListView * parent, Q3ListViewItem * after );
	PtrListViewItem ( Q3ListViewItem * parent );
	PtrListViewItem ( Q3ListView * parent );
	ItemType GetItemType();
	void SetItemType(ItemType type);
	void* GetPtr();
	void SetPtr(void* ptr);
private:
	ItemType m_type;
	void* m_ptr;
};