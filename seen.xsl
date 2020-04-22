<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"/>
  <xsl:template match="/">
    <html>
      <head>
        <style>
          body {
          background-color:#f5f5f5;
          font-family:Arial, sans-serif;
          background-image: url("wormz.png");
          color:#400040;
          }
          table {
          margin-left:auto;
          margin-right:auto;
          text-align: center;
          width:95%;

          border-collapse: collapse;
          }
          td{
          height : 24px;
          border-top: 1.5x solid magenta;
          border-collapse: collapse;

          }
          th{
          height:40px ;
          border-collapse: collapse;
          border-bottom: 2px double #00d1cb;
          color: #400040;


          }
          h1{
          text-align:center ;
          font-family: Arial, sans-serif;
          color: black;
          text-shadow: -2px 0 #00d1cb, 0 4px #00d1cb, 4px 0 #00d1cb, 0 -2px #00d1cb;
          font-size:70px;

          margin-top:20px;
          margin-bottom:10px;
          }
          img{
          width: 20%;
          display: block;
          margin-left: auto;
          margin-right: auto;
          margin-bottom: 20px;
          }
          .main1{
          background:rgba(255,255,255,0.8);
          width: 80%;
          height: 100%;
          display: block;
          margin-left: auto;
          margin-right: auto;
          margin-top:0px;

          }



        </style>
      </head>
      <body>
        <h1>Seen movies</h1>
        <div class='main1'>
    
        
        <table>
          <tr>
            <th>Title</th>
            <th>Year</th>
            <th>Rate</th>
          </tr>
          <xsl:for-each select="root/row">
            <xsl:sort select ="Year"/>
            <tr>
              <td>
                <xsl:value-of select="Title"/>
              </td>
              <td>
                <xsl:value-of select="Year"/>
              </td>
              <td>
                <xsl:value-of select="Rate"/>
              </td>
            </tr>
          </xsl:for-each>
        </table>
          <br></br>
        </div>
        
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>



