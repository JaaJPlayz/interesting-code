import { useState, useEffect } from "react";

function App() {
  const [content, setContent] = useState("");

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch("/results.txt");
        const text = await response.text();
        setContent(text);
      } catch (error) {
        console.error("Error fetching data: ", error);
      }
    };

    fetchData();
  }, []);

  return (
    <div>
      <h1>{content}</h1>
    </div>
  );
}

export default App;
