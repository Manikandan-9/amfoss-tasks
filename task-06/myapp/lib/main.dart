import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:introduction_screen/introduction_screen.dart';

void main() => runApp(Myapp());

class Myapp extends StatelessWidget {
  const Myapp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: OnboardingScreen(),
    );
  }
}


class OnboardingScreen extends StatelessWidget {
  const OnboardingScreen({Key? key}) : super(key: key);

  
  List<PageViewModel>getpages(){
    return [PageViewModel(
      title: "Yoga Surge",
      body: "Welcome to Yoga World",
      image: Image.asset("assets/images/page1.png"),


    ),
      PageViewModel(
          title: "Healthy Freaks Exercises",
          body: "Letting go is the hardest asana",
          image: Image.asset("assets/images/page2.png"),


      ),
      PageViewModel(
          title: "Cycling",
          body: "You cannot control whats going on outside,but you can always control what is going on inside",
          image: Image.asset("assets/images/page3.png"),



      ),
      PageViewModel(
          title: "Meditation",
          body: "The longest journey of any person is the journey inward",
          image: Image.asset("assets/images/page4.png"),



      )


    ];
  }
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        body: IntroductionScreen(
          pages: getpages(),
          onDone: () {
            Navigator.push(context, MaterialPageRoute(builder: (context)=>HomePage()));
          },
          done: const Text("Get Started", style: TextStyle(fontWeight: FontWeight.w600,color: Colors.black)),
          showNextButton: false,
          showSkipButton: true,
          skip: const Text("skip"),
          globalBackgroundColor: Color.fromRGBO(212, 195, 179,100),
          skipColor: Colors.black,
          dotsDecorator: DotsDecorator(
            size: const Size.square(10.0),
            activeSize: const Size(20.0, 10.0),
            activeColor: Colors.black,
            spacing: const EdgeInsets.symmetric(horizontal: 3.0),
            activeShape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(25.0))

          ),


        ),
      ),
    );


  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(title: Text("Welcome",style: TextStyle(fontSize: 15),),
        backgroundColor: Color.fromRGBO(212, 195, 179,100),
        leading: InkWell(onTap: (){
          Navigator.pop(context);
        },
        child: Icon(Icons.arrow_back_ios,size: 15,),),
        toolbarHeight: 40,),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: <Widget>[
            Image.asset("assets/images/welcome.png"),
            Text("Manikandan",style: TextStyle(fontWeight: FontWeight.bold,fontSize: 18),),
            Text("Hello I am an 18 year old boy.My hobbies are playing video games and listening to music")
          ],
        ),
      ),
    );
    
  }
}






