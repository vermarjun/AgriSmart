import { Button } from "./button";
import logo from "/leafIcon.png"

function NavbarItem(props:any){
    return (    
        <li>
            <p className="font-semibold transition-all text-lg hover:cursor-pointer hover:scale-105 hover:backdrop-filter hover:backdrop-blur-lg hover:bg-opacity-30 p-2 rounded-xl" >
                {props.text}
            </p>
        </li>
    )
}

export default function Navbar(){
    return (
        <div className="fixed top-0 left-0 z-50 flex justify-between items-center px-16 backdrop-filter backdrop-blur-lg bg-opacity-30 w-full h-20 bg-green-900">
            <div className="backdrop-filter backdrop-blur-lg bg-opacity-0 rounded-lg text-white">
                <div className="w-fit flex justify-center gap-2 items-center p-3 rounded-xl">
                    <img src={logo} alt="" className="h-8" />
                    <p className="text-2xl font-bold">Agri Smart</p>
                </div>
            </div>
            <div className="w-fit flex justify-center">
                <ul className="flex gap-10 justify-center items-center">
                    <NavbarItem text={"Home"}/>
                    <NavbarItem text={"About"}/>
                    <NavbarItem text={"Impact"}/>
                    <NavbarItem text={"Gallery"}/>
                    <NavbarItem text={"Blogs"}/>
                    <NavbarItem text={"Contact"}/>
                    <li>
                            IN
                    </li>
                    <div className="flex gap-2">
                        <li>
                            <Button className="bg-green-500 hover:bg-green-600" variant={"default"}>
                                Donate
                            </Button>
                        </li>
                        <li>
                            <Button variant={"secondary"}>
                                Login
                            </Button>
                        </li>
                    </div>
                </ul>
            </div>
        </div>
    )
}