export default function WaveAnimation() {
    return (
      <div className="relative w-screen h-screen bg-green-500 overflow-hidden">
        {/* Wave SVG */}
        <svg
          className="absolute bottom-0 left-0 w-full h-32 animate-wave"
          viewBox="0 0 1440 320"
          xmlns="http://www.w3.org/2000/svg"
        >
          <path
            fill="#4CAF50"
            fillOpacity="1"
            d="M0,192L48,208C96,224,192,256,288,240C384,224,480,160,576,154.7C672,149,768,203,864,208C960,213,1056,171,1152,149.3C1248,128,1344,128,1392,128L1440,128L1440,320L1392,320C1344,320,1248,320,1152,320C1056,320,960,320,864,320C768,320,672,320,576,320C480,320,384,320,288,320C192,320,96,320,48,320L0,320Z"
          ></path>
        </svg>
  
        {/* Tailwind Keyframes */}
        <style>
          {`
            @keyframes wave {
              0% { transform: translateX(0); }
              50% { transform: translateX(-25%); }
              100% { transform: translateX(0); }
            }
            .animate-wave {
              animation: wave 5s infinite ease-in-out;
            }
          `}
        </style>
      </div>
    );
  }