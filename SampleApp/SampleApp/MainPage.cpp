#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::SampleApp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        if (varGrid().Children().Size() > 0)
        {
            varGrid().Children().Clear();
        }
        int numOfItems = _wtoi(countText().Text().c_str());
        Windows::Foundation::Collections::IVector<IInspectable> listViewItems = winrt::single_threaded_observable_vector<IInspectable>();
        for (int t = 1; t <= numOfItems; t++)
        {
            Windows::UI::Xaml::Controls::ListView newListView = Windows::UI::Xaml::Controls::ListView();
            for (int itemCount = 1; itemCount < 100; ++itemCount)
            {
                hstring itemText = L"Item " + to_hstring(itemCount);
                listViewItems.Append(box_value(itemText));
            }
            newListView.ItemsSource(listViewItems);
            newListView.Height(50);
            newListView.Width(60);
            Thickness thickness;
            thickness.Left = 0.60;
            thickness.Top = 0.60;
            thickness.Bottom = 0.60;
            thickness.Right = 0.60;
            newListView.Margin(thickness);
            newListView.VerticalAlignment(VerticalAlignment::Top);
            newListView.HorizontalAlignment(HorizontalAlignment::Left);
            varGrid().Children().Append(newListView);
        }
    }
}
