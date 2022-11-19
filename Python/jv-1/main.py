import kivy
from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.image import Image,AsyncImage
from kivy.uix.button import Button


class LoginScreen(GridLayout):
    def __init__(self, **kwargs):
        super(LoginScreen, self).__init__(**kwargs)
        self.cols = 2
        self.add_widget(Label(text='User Name'))
        self.username = TextInput(multiline=False)
        self.add_widget(self.username)
        self.add_widget(Label(text='password'))
        self.password = TextInput(password=True, multiline=False)
        self.add_widget(self.password)

class MyApp(App):
    def build(self):
        self.title="农+"
        layout = GridLayout(cols = 1)
        layout.add_widget(Label(text="q"))
        layout.add_widget(Image(source="SRC/2.png"))
        return layout
if __name__ == '__main__':
    MyApp().run()
