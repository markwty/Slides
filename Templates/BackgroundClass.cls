VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "BackgroundClass"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Public WithEvents App As Application
Attribute App.VB_VarHelpID = -1
Dim animation_counts() As Integer
Dim slide_count As Long
Dim trigger As Boolean

Private Sub App_SlideShowBegin(ByVal Window As SlideShowWindow)
    Dim slide_index, slide_num, animate_num As Long
    Dim slid As Slide
    slide_num = 0
    slide_count = ActivePresentation.Slides.Count
    ReDim animation_counts(slide_count)
    For Each slid In ActivePresentation.Slides
        animate_num = slid.TimeLine.MainSequence.Count
        If (animate_num > 0) Then
            animation_counts(slide_num) = (animate_num - 1) / 2 + 1
        Else
            animation_counts(slide_num) = 0
        End If
        slide_num = slide_num + 1
    Next
    trigger = True
End Sub

Private Sub App_SlideShowNextSlide(ByVal Window As SlideShowWindow)
    Dim slide_index, store_index, slide_num, i As Long
    If (Not trigger) Then
        trigger = True
        Exit Sub
    End If
    slide_index = Window.View.Slide.SlideIndex
    store_index = slide_index
    For i = 1 To slide_count
        store_index = store_index - animation_counts(i - 1)
        If (store_index <= 0) Then
            slide_num = i
            Exit For
        End If
    Next i
    If (store_index > 0) Then
        Exit Sub
    End If
    trigger = False
    Window.View.GotoSlide slide_num
    If (slide_index - slide_num = 0) Then
        'Does not go here if there is no change in slide number
        Call Window.View.GotoClick(0)
    Else
        Call Window.View.GotoClick(slide_index - slide_num - 1)
    End If
End Sub
