#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MelissaFileListBox.h"

class MelissaSetListComponent : public Component
{
public:
    MelissaSetListComponent(MelissaHost* host);
    
    void createUI();
    const Array<var>& getData();
    void setData(const Array<var>& data);
    void update();
    void select(int index);
    void createSetlist(const String& name, bool shouldSelect = false);
    enum { kIndex_Current = -1 };
    void addToSetlist(const String& filePath, int index = kIndex_Current);
    
    // Component
    void resized() override;
    
private:
    Array<var>* getCurrentSongList();
    
    MelissaHost* host_;
    Array<var> data_;
    std::unique_ptr<FileChooser> fileChooser_;
    std::unique_ptr<ComboBox> setListComboBox_;
    std::unique_ptr<TextButton> newSetListButton_;
    std::unique_ptr<TextButton> removeSetListButton_;
    std::unique_ptr<TextButton> addToSetListButton_;
    std::unique_ptr<MelissaFileListBox> listBox_;
};
