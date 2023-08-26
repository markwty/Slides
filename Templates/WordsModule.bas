Attribute VB_Name = "WordsModule"

Public Sub DoMergeShapes(slide_num As Integer)
	If (ActivePresentation.Slides(slide_num).shapes.Count > 1) then
		ActivePresentation.Slides(slide_num).Shapes.Range.MergeShapes(4)
	End If
End Sub
