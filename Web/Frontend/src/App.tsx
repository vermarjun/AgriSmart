import Navbar from "./components/ui/navbar"
import Home from "./components/Home"
import Problem from "./components/Problem"
import chatBubble from "/chatBubble.png"
import WhoAreWe from "./components/WhoAreWe"
import ReachUs from "./components/ReachUs"
import Footer from "./components/Footer"
import Carousel from "./components/RecognitionCarousel"

export function ChatButton(){
  return (
    <div className="fixed right-8 rounded-xl bottom-10 flex flex-col justify-center items-center">
        <img src={chatBubble} alt="" className="h-14"/>
        <p className="font-semibold text-xs">AI Chat Bot</p>
    </div>
  )
}

export default function App() {
  return (
    <div className={`flex flex-col items-center h-fit max-w-screen overflow-x-hidden`}>
      <Navbar/>
      <ChatButton/>
      <Home/>
      <Problem/>
      <WhoAreWe/  >
      <Carousel/>
      <ReachUs/>
      <Footer/>
    </div>
  )
}
